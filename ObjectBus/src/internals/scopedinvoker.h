#ifndef SCOPEDINVOKER_H
#define SCOPEDINVOKER_H

#include <QObject>
#include <QHash>
#include <QVector>

class ScopedInvoker : public QObject
{
public:
    ScopedInvoker();
    virtual ~ScopedInvoker();

public:
    bool attach(const QObject *sender, const char *signal, const char *mapped);
    bool detach(const QObject *sender, const char *signal, const char *mapped);

    void notify(const char *mapped, const QVariant **a, int c);

    bool attach(const char *mapped, const QObject *receiver, const char *method);
    bool detach(const char *mapped, const QObject *receiver, const char *method);

protected:
    int qt_metacall(QMetaObject::Call c, int id, void **a) Q_DECL_FINAL;

private:
    int mappedId(const QByteArray &mapped);

private:
    int idGenerator;
    QHash<QByteArray, int> methodIds;
    QHash<int, QVector<int> > argumentTypes;
};

ScopedInvoker *theScopedInvoker();

#endif // SCOPEDINVOKER_H
