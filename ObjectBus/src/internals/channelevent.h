#ifndef CHANNELEVENT_H
#define CHANNELEVENT_H
#ifndef QT_NO_THREAD

#include <QEvent>
#include <QSharedPointer>
#include <QVector>

class ChannelEvent : public QEvent
{
    struct SharedDataPrivate
    {
        int id;
        void **arguments;
        QVector<int> argumentTypes;
    };

public:
    typedef QSharedPointer<SharedDataPrivate> SharedData;
public:
    explicit ChannelEvent(const SharedData &d);

public:
    static SharedData create(int id, void **a);
    static SharedData create(const char *method, int id,
                             const QVariant **a, int c);
    static void staticDeleter(SharedDataPrivate *d);

public:
    SharedData sharedData() const;
private:
    SharedData m_sharedData;
};

inline ChannelEvent::SharedData ChannelEvent::sharedData() const
{
    return m_sharedData;
}

#endif // QT_NO_THREAD
#endif // CHANNELEVENT_H
