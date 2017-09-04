#ifndef QT_NO_THREAD

#include "SharedInvoker.h"

#include <QCoreApplication>
#include <QThread>
#include <QThreadStorage>

#include "ChannelEvent.h"
#include "ChannelShared.h"
#include "ChannelFuncs.h"

using namespace ChannelPrivate;

// Global SharedInvokers

QThreadStorage<SharedInvoker *> theSharedInvokers;

SharedInvoker *theSharedInvoker()
{
    SharedInvoker *invoker = theSharedInvokers.localData();
    if (!invoker) {
        invoker = new SharedInvoker();
        theSharedInvokers.setLocalData(invoker);
    }
    return invoker;
}

// class SharedInvoker

SharedInvoker::SharedInvoker()
{
    ChannelShared *shared = theChannelShared();
    QWriteLocker sharedLocker(&shared->siblingLock);

    QVectorIterator<SharedInvoker *> i(shared->siblings);
    while (i.hasNext()) {
        SharedInvoker *invoker = i.next();
        QWriteLocker invokerLocker(&invoker->siblingLock);

        invoker->siblings.append(this);
        siblings.append(invoker);
    }

    shared->siblings.append(this);
}

SharedInvoker::~SharedInvoker()
{
    ChannelShared *shared = theChannelShared();
    QWriteLocker sharedLocker(&shared->siblingLock);

    QVectorIterator<SharedInvoker *> i(shared->siblings);
    while (i.hasNext()) {
        SharedInvoker *invoker = i.next();
        QWriteLocker invokerLocker(&invoker->siblingLock);

        invoker->siblings.removeOne(this);
    }

    shared->siblings.removeOne(this);
}

bool SharedInvoker::attach(const QObject *sender, const char *signal, const char *mapped)
{
    QByteArray theSignal = QMetaObject::normalizedSignature(signal);
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);

    if (!QMetaObject::checkConnectArgs(theSignal, theMapped)) {
        const char *senderName = sender->metaObject()->className();
        checkArgs("SharedChannel", senderName, signal, "SharedChannel", mapped);
        return false;
    }

    const QMetaObject *metaObject = sender->metaObject();
    int signalId = metaObject->indexOfSignal(theSignal.constData() + 1);
    if (signalId < 0) {
        methodNotFound("SharedChannel",
                       "attach", sender, signal);
        return false;
    }

    ChannelShared *shared = theChannelShared();
    int mappedId = shared->mappedId(theMapped);
    Q_ASSERT_X(mappedId > 0, "SharedChannel", "bad id");
    return QMetaObject::connect(sender, signalId, this, mappedId,
                                Qt::DirectConnection | Qt::UniqueConnection);
}

bool SharedInvoker::detach(const QObject *sender, const char *signal, const char *mapped)
{
    QByteArray theSignal = QMetaObject::normalizedSignature(signal);
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);

    const QMetaObject *metaObject = sender->metaObject();
    int signalId = metaObject->indexOfSignal(theSignal.constData() + 1);
    if (signalId < 0) {
        methodNotFound("SharedChannel",
                       "detach", sender, signal);
        return false;
    }

    ChannelShared *shared = theChannelShared();
    int mappedId = shared->mappedId(theMapped);
    Q_ASSERT_X(mappedId > 0, "SharedChannel", "bad id");
    return QMetaObject::disconnect(sender, signalId, this, mappedId);
}

void SharedInvoker::notify(const char *mapped, const QVariant **a, int c)
{
    ChannelShared *shared = theChannelShared();
    QReadLocker sharedLocker(&shared->siblingLock);

    if (shared->siblings.isEmpty()) {
        return;
    }

    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);
    int mappedId = shared->methodIds.value(theMapped, -1);
    if (mappedId < 0) {
        return;
    }

    ChannelEvent::SharedData data = ChannelEvent::create(mapped, mappedId, a, c);
    if (data) {
        SharedInvoker *currentInvoker = 0;
        QVectorIterator<SharedInvoker *> i(shared->siblings);
        while (i.hasNext()) {
            SharedInvoker *invoker = i.next();
            if (invoker->thread() != QThread::currentThread()) {
                QCoreApplication::postEvent(invoker, new ChannelEvent(data));
            } else {
                currentInvoker = invoker;
            }
        }

        if (currentInvoker) {
            sharedLocker.unlock();
            QMetaObject::activate(currentInvoker, 0,
                                  data->id, data->arguments);
        }
    }
}

bool SharedInvoker::attach(const char *mapped, const QObject *receiver, const char *method)
{
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);
    QByteArray theMethod = QMetaObject::normalizedSignature(method);

    if (!QMetaObject::checkConnectArgs(theMapped, theMethod)) {
        const char *receiverName = receiver->metaObject()->className();
        checkArgs("SharedChannel", "SharedChannel", mapped, receiverName, method);
        return false;
    }

    const QMetaObject *metaObject = receiver->metaObject();
    int methodId = metaObject->indexOfMethod(theMethod.constData() + 1);
    if (methodId < 0) {
        methodNotFound("SharedChannel",
                       "attach", receiver, method);
        return false;
    }

    ChannelShared *shared = theChannelShared();
    int mappedId = shared->mappedId(theMapped);
    Q_ASSERT_X(mappedId > 0, "SharedChannel", "bad id");
    return QMetaObject::connect(this, mappedId, receiver, methodId,
                                Qt::DirectConnection | Qt::UniqueConnection);
}

bool SharedInvoker::detach(const char *mapped, const QObject *receiver, const char *method)
{
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);
    QByteArray theMethod = QMetaObject::normalizedSignature(method);

    const QMetaObject *metaObject = receiver->metaObject();
    int methodId = metaObject->indexOfMethod(theMethod.constData() + 1);
    if (methodId < 0) {
        methodNotFound("SharedChannel",
                       "detach", receiver, method);
        return false;
    }

    ChannelShared *shared = theChannelShared();
    int mappedId = shared->mappedId(theMapped);
    Q_ASSERT_X(mappedId > 0, "SharedChannel", "bad id");
    return QMetaObject::disconnect(this, mappedId, receiver, methodId);
}

int SharedInvoker::qt_metacall(QMetaObject::Call c, int id, void **a)
{
    int methodId = QObject::qt_metacall(c, id, a);
    if ((methodId < 0) || (QMetaObject::InvokeMetaMethod != c)) {
        return methodId;
    }

    ChannelShared *shared = theChannelShared();
    QReadLocker sharedLocker(&shared->siblingLock);

    if (shared->argumentTypes.contains(id)) {
        QReadLocker invokerLocker(&siblingLock);

        if (!siblings.isEmpty()) {
            ChannelEvent::SharedData data
                    = ChannelEvent::create(id, a);
            if (data) {
                QVectorIterator<SharedInvoker *> i(siblings);
                while (i.hasNext()) {
                    QCoreApplication::postEvent(i.next(),
                                                new ChannelEvent(data));
                }
            }
        }
        sharedLocker.unlock();

        QMetaObject::activate(this, 0, id, a);
    }

    return -1;
}

bool SharedInvoker::event(QEvent *e)
{
    if (e->type() != ChannelShared::staticEventType) {
        return QObject::event(e);
    }

    ChannelEvent *channelEvent = static_cast<ChannelEvent *>(e);
    ChannelEvent::SharedData data = channelEvent->sharedData();
    QMetaObject::activate(this, 0, data->id, data->arguments);

    return true;
}

#endif // QT_NO_THREAD
