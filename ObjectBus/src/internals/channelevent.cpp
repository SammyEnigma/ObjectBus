#ifndef QT_NO_THREAD

#include "ChannelEvent.h"

#include <QMetaType>
#include <QVariant>

#include "ChannelFuncs.h"
#include "ChannelShared.h"

using namespace ChannelPrivate;

// class ChannelEvent

ChannelEvent::ChannelEvent(const SharedData &d)
    : QEvent(static_cast<Type>(ChannelShared::staticEventType))
    , m_sharedData(d)
{
}

ChannelEvent::SharedData ChannelEvent::create(int id, void **a)
{
    ChannelShared *shared = theChannelShared();
    const QVector<int> &argTypes = shared->argumentTypes[id];

    SharedData data(new SharedDataPrivate(), staticDeleter);
    int size = (argTypes.count() + 1) * sizeof(quintptr);
    data->arguments = static_cast<void **>(malloc(size));

    data->id = id;
    data->arguments[0] = 0;
    data->argumentTypes = argTypes;

    for (int i = 0; i < argTypes.count(); ++i) {
        data->arguments[i + 1] = QMetaType::create(argTypes[i], a[i + 1]);
    }

    return data;
}

ChannelEvent::SharedData ChannelEvent::create(const char *method, int id, const QVariant **a, int c)
{
    ChannelShared *shared = theChannelShared();
    const QVector<int> &argTypes = shared->argumentTypes[id];
    if (argTypes.count() != c) {
        argumentNotEnough("SharedChannel",
                          method, argTypes.count(), c);
        return SharedData();
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
                argumentNotMatch("SharedChannel",
                                 method, i, typeId, *v);
                for (int j = 0; j < index; ++j) {
                    delete cvtArgs[j];
                }
                return SharedData();
            }
        } else {
            argumentNotMatch("SharedChannel",
                             method, i, typeId, *v);
            for (int j = 0; j < index; ++j) {
                delete cvtArgs[j];
            }
            return SharedData();
        }
    }

    SharedData data(new SharedDataPrivate(), staticDeleter);
    int size = (argTypes.count() + 1) * sizeof(quintptr);
    data->arguments = static_cast<void **>(malloc(size));

    data->id = id;
    data->arguments[0] = 0;
    data->argumentTypes = argTypes;

    for (int i = 0; i < argTypes.count(); ++i) {
        data->arguments[i + 1] = QMetaType::create(argTypes[i], args[i + 1]);
    }
    for (int i = 0; i < index; ++i) {
        delete cvtArgs[i];
    }

    return data;
}

void ChannelEvent::staticDeleter(ChannelEvent::SharedDataPrivate *d)
{
    if (!d->argumentTypes.isEmpty()
            && (Q_NULLPTR != d->arguments)) {
        for (int i = 0; i < d->argumentTypes.count(); ++i) {
            QMetaType::destroy(d->argumentTypes[i], d->arguments[i + 1]);
        }
        free(d->arguments);
    }

    delete d;
}

#endif // QT_NO_THREAD
