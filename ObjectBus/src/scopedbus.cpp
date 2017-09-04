#include "../include/ScopedBus.h"

#include "internals/ScopedInvoker.h"

namespace ScopedBus {

bool attach(const QObject *sender, const char *signal, const char *mapped)
{
    return theScopedInvoker()->attach(sender, signal, mapped);
}

bool detach(const QObject *sender, const char *signal, const char *mapped)
{
    return theScopedInvoker()->detach(sender, signal, mapped);
}

bool attach(const char *mapped, const QObject *receiver, const char *method)
{
    return theScopedInvoker()->attach(mapped, receiver, method);
}

bool detach(const char *mapped, const QObject *receiver, const char *method)
{
    return theScopedInvoker()->detach(mapped, receiver, method);
}

void notify(const char *mapped)
{
    theScopedInvoker()->notify(mapped, 0, 0);
}

void notify(const char *mapped, const QVariant &a0)
{
    const QVariant *a[] = { &a0 };

    theScopedInvoker()->notify(mapped, a, 1);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1)
{
    const QVariant *a[] = { &a0, &a1 };

    theScopedInvoker()->notify(mapped, a, 2);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2)
{
    const QVariant *a[] = { &a0, &a1, &a2 };

    theScopedInvoker()->notify(mapped, a, 3);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3 };

    theScopedInvoker()->notify(mapped, a, 4);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4 };

    theScopedInvoker()->notify(mapped, a, 5);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                            const QVariant &a5)

{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5 };

    theScopedInvoker()->notify(mapped, a, 6);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                            const QVariant &a5, const QVariant &a6)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5, &a6 };

    theScopedInvoker()->notify(mapped, a, 7);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                            const QVariant &a5, const QVariant &a6, const QVariant &a7)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7 };

    theScopedInvoker()->notify(mapped, a, 8);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                            const QVariant &a5, const QVariant &a6, const QVariant &a7, const QVariant &a8)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8 };

    theScopedInvoker()->notify(mapped, a, 9);
}

void notify(const char *mapped, const QVariant &a0, const QVariant &a1, const QVariant &a2, const QVariant &a3, const QVariant &a4,
                            const QVariant &a5, const QVariant &a6, const QVariant &a7, const QVariant &a8, const QVariant &a9)
{
    const QVariant *a[] = { &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9 };

    theScopedInvoker()->notify(mapped, a, 10);
}

}//namespace ScopedBus
