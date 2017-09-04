#ifndef SHAREDINVOKER_H
#define SHAREDINVOKER_H
#ifndef QT_NO_THREAD

#include <QObject>
#include <QReadWriteLock>
#include <QVector>

class SharedInvoker : public QObject
{
public:
    SharedInvoker();
    virtual ~SharedInvoker();

public:
    bool attach(const QObject *sender, const char *signal, const char *mapped);
    bool detach(const QObject *sender, const char *signal, const char *mapped);

    void notify(const char *mapped, const QVariant **a, int c);

    bool attach(const char *mapped, const QObject *receiver, const char *method);
    bool detach(const char *mapped, const QObject *receiver, const char *method);

protected:
    int qt_metacall(QMetaObject::Call c, int id, void **a) Q_DECL_FINAL;
    bool event(QEvent *e) Q_DECL_FINAL;

private:
    QVector<SharedInvoker *> siblings;
    QReadWriteLock           siblingLock;
};

SharedInvoker *theSharedInvoker();

#endif // QT_NO_THREAD
#endif // SHAREDINVOKER_H
