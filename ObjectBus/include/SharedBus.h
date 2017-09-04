#ifndef SHAREDBUS_H
#define SHAREDBUS_H

#include <QObject>

#ifndef OBJECTBUS_MAPPED
#define OBJECTBUS_MAPPED(a) SIGNAL(a)
#ifndef MAPPED
#define MAPPED(a) OBJECTBUS_MAPPED(a)
#endif//MAPPED
#endif//OBJECTBUS_MAPPED

namespace SharedBus {

bool attach(const QObject *sender, const char *signal, const char *mapped);
bool detach(const QObject *sender, const char *signal, const char *mapped);

void notify(const char *mapped);
void notify(const char *mapped, const QVariant &a0);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
            const QVariant &a5);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
            const QVariant &a5, const QVariant &a6);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
            const QVariant &a5, const QVariant &a6, const QVariant &a7);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
            const QVariant &a5, const QVariant &a6, const QVariant &a7, const QVariant &a8);
void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
            const QVariant &a5, const QVariant &a6, const QVariant &a7, const QVariant &a8, const QVariant &a9);

bool attach(const char *mapped, const QObject *receiver, const char *method);
bool detach(const char *mapped, const QObject *receiver, const char *method);

}//namespace SharedBus

#endif//SHAREDBUS_H
