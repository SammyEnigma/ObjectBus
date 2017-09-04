#ifndef CHANNELFUNCS_H
#define CHANNELFUNCS_H

#include <QObject>
#include <QVector>

namespace ChannelPrivate {

QVector<QByteArray> argumentTypeNamesFromSignature(const char *signature);

void checkArgs(const char *className, const char *sender, const char *signal, const char *receiver, const char *method);
void methodNotFound(const char *className, const char *function, const QObject *object, const char *method);
void argumentNotMatch(const char *className, const char *method, int pos, int type, const QVariant &value);
void argumentNotEnough(const char *className, const char *method, int requiredNumber, int actualNumber);

} // namespace ChannelPrivate

#endif // CHANNELFUNCS_H
