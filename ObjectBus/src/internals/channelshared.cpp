#ifndef QT_NO_THREAD

#include "ChannelShared.h"

#include <QEvent>

#include "ChannelFuncs.h"

using namespace ChannelPrivate;

// Global ChannelShared

Q_GLOBAL_STATIC(ChannelShared, theChannelShared2)

ChannelShared *theChannelShared()
{
    return theChannelShared2();
}

// class ChannelShared

const int ChannelShared::staticEventType = QEvent::registerEventType(2015);

ChannelShared::ChannelShared()
    : idGenerator(2015)
{
}

ChannelShared::~ChannelShared()
{
}

int ChannelShared::mappedId(const QByteArray &mapped)
{
    int mappedId = -1;

    do {
        QReadLocker sharedLocker(&siblingLock);
        mappedId = methodIds.value(mapped, -1);
    } while (false);

    if (mappedId < 0) {
        QWriteLocker sharedLocker(&siblingLock);
        mappedId = methodIds.value(mapped, -1);

        if (mappedId < 0) {
            mappedId = ++idGenerator;
            methodIds.insert(mapped, mappedId);

            QVector<int> argumentType;
            QVector<QByteArray> argumentTypeNames
                    = argumentTypeNamesFromSignature(mapped);
            Q_FOREACH (const QByteArray &typeName, argumentTypeNames) {
                int type = QMetaType::type(typeName);
                if (type != QMetaType::UnknownType) {
                    argumentType << type;
                } else {
                    return -1;
                }
            }
            argumentTypes.insert(mappedId, argumentType);
            // qDebug() << mapped << mappedId << argumentType;
        }
    }

    return mappedId;
}

#endif // QT_NO_THREAD
