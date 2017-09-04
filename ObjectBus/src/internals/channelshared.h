#ifndef CHANNELSHARED_H
#define CHANNELSHARED_H
#ifndef QT_NO_THREAD

#include <QByteArray>
#include <QHash>
#include <QReadWriteLock>
#include <QVector>

class SharedInvoker;
class ChannelShared
{
public:
    ChannelShared();
    virtual ~ChannelShared();

public:
    QVector<SharedInvoker *> siblings;
    QReadWriteLock           siblingLock;

public:
    int mappedId(const QByteArray &mapped);
public:
    int idGenerator;
    QHash<QByteArray, int> methodIds;
    QHash<int, QVector<int> > argumentTypes;
    static const int staticEventType;
};

ChannelShared *theChannelShared();

#endif // QT_NO_THREAD
#endif // CHANNELSHARED_H
