#include "ScopedInvoker.h"

#ifndef QT_NO_THREAD
#  include <QThreadStorage>
#endif//QT_NO_THREAD

#include <QVariant>

#include "ChannelFuncs.h"

using namespace ChannelPrivate;

// Global SharedInvokers

#ifndef QT_NO_THREAD

QThreadStorage<ScopedInvoker *> tinyInvokers;
ScopedInvoker *theScopedInvoker()
{
    ScopedInvoker *invoker = tinyInvokers.localData();
    if (Q_NULLPTR == invoker) {
        invoker = new ScopedInvoker();
        tinyInvokers.setLocalData(invoker);
    }
    return invoker;
}

#else

ScopedInvoker *theScopedInvoker()
{
    static ScopedInvoker invoker;
    return &invoker;
}

#endif//QT_NO_THREAD

// class SharedInvoker

ScopedInvoker::ScopedInvoker()
    : idGenerator(1986)
{
}

ScopedInvoker::~ScopedInvoker()
{
}

bool ScopedInvoker::attach(const QObject *sender, const char *signal, const char *mapped)
{
    QByteArray theSignal = QMetaObject::normalizedSignature(signal);
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);

    if (!QMetaObject::checkConnectArgs(theSignal, theMapped)) {
        const char *senderName = sender->metaObject()->className();
        checkArgs("ScopedChannel", senderName, signal, "ScopedChannel", mapped);
        return false;
    }

    const QMetaObject *metaObject = sender->metaObject();
    int signalId = metaObject->indexOfSignal(theSignal.constData() + 1);
    if (signalId < 0) {
        methodNotFound("ScopedChannel",
                       "attach", sender, signal);
        return false;
    }

    int mappedId = this->mappedId(theMapped);
    Q_ASSERT_X(mappedId > 0, "ScopedChannel", "bad id");
    return QMetaObject::connect(sender, signalId, this, mappedId,
                                Qt::DirectConnection | Qt::UniqueConnection);
}

bool ScopedInvoker::detach(const QObject *sender, const char *signal, const char *mapped)
{
    QByteArray theSignal = QMetaObject::normalizedSignature(signal);
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);

    const QMetaObject *metaObject = sender->metaObject();
    int signalId = metaObject->indexOfSignal(theSignal.constData() + 1);
    if (signalId < 0) {
        methodNotFound("ScopedChannel",
                       "detach", sender, signal);
        return false;
    }

    int mappedId = this->mappedId(theMapped);
    Q_ASSERT_X(mappedId > 0, "ScopedChannel", "bad id");
    return QMetaObject::disconnect(sender, signalId, this, mappedId);
}

void ScopedInvoker::notify(const char *mapped, const QVariant **a, int c)
{
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);
    int mappedId = this->methodIds.value(theMapped, -1);
    if (mappedId < 0) {
        return;
    }

    const QVector<int> &argTypes = argumentTypes[mappedId];
    if (c != argTypes.count()) {
        argumentNotEnough("ScopedChannel",
                          mapped, argTypes.count(), c);
        return;
    }

    int index = 0;
    void *args[11] = {0};
    QVariant *cvtArgs[10] = {0};

    for (int i = 0; i < c; ++i) {
        int typeId = argTypes.at(i);
        const QVariant *v = a[i];

        if (static_cast<int>(v->type()) == typeId) {
            args[i + 1] = const_cast<void *>(v->data());
        } else if (v->canConvert(typeId)) {
            QVariant *n = new QVariant(*v);
            cvtArgs[index] = n;
            ++index;

            if (n->convert(typeId)) {
                args[i + 1] = const_cast<void *>(n->data());
            } else {
                argumentNotMatch("ScopedChannel",
                                 mapped, i, typeId, *v);
                for (int j = 0; j < index; ++j) {
                    delete cvtArgs[j];
                }
                return;
            }
        } else {
            argumentNotMatch("ScopedChannel",
                             mapped, i, typeId, *v);
            for (int j = 0; j < index; ++j) {
                delete cvtArgs[j];
            }
            return;
        }
    }

    QMetaObject::activate(this, 0, mappedId, args);
    for (int i = 0; i < index; ++i) {
        delete cvtArgs[i];
    }
}

bool ScopedInvoker::attach(const char *mapped, const QObject *receiver, const char *method)
{
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);
    QByteArray theMethod = QMetaObject::normalizedSignature(method);

    if (!QMetaObject::checkConnectArgs(theMapped, theMethod)) {
        const char *receiverName = receiver->metaObject()->className();
        checkArgs("ScopedChannel", "ScopedChannel", mapped, receiverName, method);
        return false;
    }

    const QMetaObject *metaObject = receiver->metaObject();
    int methodId = metaObject->indexOfMethod(theMethod.constData() + 1);
    if (methodId < 0) {
        methodNotFound("ScopedChannel",
                       "attach", receiver, method);
        return false;
    }

    int mappedId = this->mappedId(theMapped);
    Q_ASSERT_X(mappedId > 0, "ScopedChannel", "bad id");
    return QMetaObject::connect(this, mappedId, receiver, methodId,
                                Qt::DirectConnection | Qt::UniqueConnection);
}

bool ScopedInvoker::detach(const char *mapped, const QObject *receiver, const char *method)
{
    QByteArray theMapped = QMetaObject::normalizedSignature(mapped);
    QByteArray theMethod = QMetaObject::normalizedSignature(method);

    const QMetaObject *metaObject = receiver->metaObject();
    int methodId = metaObject->indexOfMethod(theMethod.constData() + 1);
    if (methodId < 0) {
        methodNotFound("ScopedChannel",
                       "detach", receiver, method);
        return false;
    }

    int mappedId = this->mappedId(theMapped);
    Q_ASSERT_X(mappedId > 0, "ScopedChannel", "bad id");
    return QMetaObject::disconnect(this, mappedId, receiver, methodId);
}

int ScopedInvoker::qt_metacall(QMetaObject::Call c, int id, void **a)
{
    int methodId = QObject::qt_metacall(c, id, a);
    if ((methodId < 0) || (QMetaObject::InvokeMetaMethod != c)) {
        return methodId;
    }

    QMetaObject::activate(this, 0, id, a);

    return -1;
}

int ScopedInvoker::mappedId(const QByteArray &mapped)
{
    int mappedId = methodIds.value(mapped, -1);

    if (mappedId < 0) {
        mappedId = ++idGenerator;
        methodIds.insert(mapped, mappedId);

        QVector<int> argumentType;
        QVector<QByteArray> argumentTypeNames
                = argumentTypeNamesFromSignature(mapped);
        Q_FOREACH (const QByteArray &typeName, argumentTypeNames) {
            int type = QMetaType::type(typeName);
            if (QMetaType::UnknownType != type) {
                argumentType << type;
            } else {
                return -1;
            }
        }
        argumentTypes.insert(mappedId, argumentType);
    }

    return mappedId;
}
