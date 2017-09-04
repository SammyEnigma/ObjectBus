#include "../include/SharedBus.h"

#include "internals/SharedInvoker.h"
#include "internals/ScopedInvoker.h"

namespace SharedBus {

bool attach(const QObject *sender, const char *signal, const char *mapped)
{
#ifndef QT_NO_THREAD
    return theSharedInvoker()->attach(sender, signal, mapped);
#else
    return theScopedInvoker()->attach(sender, signal, mapped);
#endif//QT_NO_THREAD
}

bool detach(const QObject *sender, const char *signal, const char *mapped)
{
#ifndef QT_NO_THREAD
    return theSharedInvoker()->detach(sender, signal, mapped);
#else
    return theScopedInvoker()->detach(sender, signal, mapped);
#endif//QT_NO_THREAD
}

bool attach(const char *mapped, const QObject *receiver, const char *method)
{
#ifndef QT_NO_THREAD
    return theSharedInvoker()->attach(mapped, receiver, method);
#else
    return theScopedInvoker()->attach(mapped, receiver, method);
#endif//QT_NO_THREAD
}

bool detach(const char *mapped, const QObject *receiver, const char *method)
{
#ifndef QT_NO_THREAD
    return theSharedInvoker()->detach(mapped, receiver, method);
#else
    return theScopedInvoker()->detach(mapped, receiver, method);
#endif//QT_NO_THREAD
}

void notify(const char *mapped)
{
#ifndef QT_NO_THREAD
    return theSharedInvoker()->notify(mapped, 0, 0);
#else
    return theScopedInvoker()->notify(mapped, 0, 0);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0)
{
    const QVariant *a[] = { &a0 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 1);
#else
    theScopedInvoker()->notify(mapped, a, 1);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1)
{
    const QVariant *a[] = { &a0, &a1 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 2);
#else
    theScopedInvoker()->notify(mapped, a, 2);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2)
{
    const QVariant *a[] = { &a0, &a1, &a2 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 3);
#else
    theScopedInvoker()->notify(mapped, a, 3);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 4);
#else
    theScopedInvoker()->notify(mapped, a, 4);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 5);
#else
    theScopedInvoker()->notify(mapped, a, 5);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                      const QVariant &a5)

{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 6);
#else
    theScopedInvoker()->notify(mapped, a, 6);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                      const QVariant &a5, const QVariant &a6)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5, &a6 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 7);
#else
    theScopedInvoker()->notify(mapped, a, 7);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                      const QVariant &a5, const QVariant &a6, const QVariant &a7)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 8);
#else
    theScopedInvoker()->notify(mapped, a, 8);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                      const QVariant &a5, const QVariant &a6, const QVariant &a7, const QVariant &a8)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 9);
#else
    theScopedInvoker()->notify(mapped, a, 9);
#endif//QT_NO_THREAD
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                      const QVariant &a5, const QVariant &a6, const QVariant &a7, const QVariant &a8, const QVariant &a9)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9 };

#ifndef QT_NO_THREAD
    theSharedInvoker()->notify(mapped, a, 10);
#else
    theScopedInvoker()->notify(mapped, a, 10);
#endif//QT_NO_THREAD
}

}//namespace SharedBus
