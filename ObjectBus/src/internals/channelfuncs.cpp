#include "ChannelFuncs.h"

#include <QVariant>

namespace ChannelPrivate {

// QObject.cpp private functions.

const char *extract_location(const char *method)
{
    const char *location = method + qstrlen(method) + 1;
    if (*location != '\0') {
        return location;
    }

    return 0;
}

// QMetaObject.cpp private functions.

QVector<QByteArray> argumentTypeNamesFromSignature(const char *signature)
{
    QVector<QByteArray> list;
    while (*signature && *signature != '(')
        ++signature;
    while (*signature && *signature != ')' && *++signature != ')') {
        const char *begin = signature;
        int level = 0;
        while (*signature && (level > 0 || *signature != ',') && *signature != ')') {
            if (*signature == '<')
                ++level;
            else if (*signature == '>')
                --level;
            ++signature;
        }
        list += QByteArray(begin, signature - begin);
    }
    return list;
}

// QObject.cpp private functions.

void checkArgs(const char *className, const char *sender, const char *signal, const char *receiver, const char *method)
{
    const char *loc = extract_location(method);
    qWarning("%s::attach: Incompatible sender/receiver arguments%s%s"
             "\n        %s::%s --> %s::%s",
             className, loc ? " in ": "", loc ? loc : "",
             sender, signal + 1, receiver, method + 1);
}

void methodNotFound(const char *className, const char *function, const QObject *object, const char *method)
{
    const char *type = "method";

    switch (method[0] & 0x03) {
    case QSLOT_CODE:
        type = "slot";
        break;
    case QSIGNAL_CODE:
        type = "signal";
        break;
    }

    // common typing mistake
    const char *loc = extract_location(method);
    if (strchr(method, ')') == 0) {
        qWarning("%s::%s: Parentheses expected, %s %s::%s%s%s", className,
                 function, type, object->metaObject()->className(), method + 1,
                 loc ? " in ": "", loc ? loc : "");
    } else {
        qWarning("%s::%s: No such %s %s::%s%s%s", className,
                 function, type, object->metaObject()->className(), method + 1,
                 loc ? " in ": "", loc ? loc : "");
    }
}

void argumentNotMatch(const char *className, const char *method, int pos, int type, const QVariant &value)
{
    const char *loc = extract_location(method);
    qWarning("%s::notify: Incompatible argument%s%s"
             "\n        %s::%s, %d, %s --> %s",
             className, loc ? " in ": "", loc ? loc : "",
             className, method + 1, pos, value.typeName(), QVariant::typeToName(type));
}

void argumentNotEnough(const char *className, const char *method, int expectedNumber, int actualNumber)
{
    const char *loc = extract_location(method);
    qWarning("%s::notify: Insufficient argument%s%s"
             "\n        %s::%s, expected %d parameter(s), but got %d",
             className, loc ? " in ": "", loc ? loc : "",
             className, method + 1, expectedNumber, actualNumber);
}

} // namespace ChannelPrivate
