#pragma execution_character_set("utf-8")

#include "mansignals.h"


ManSignals::ManSignals(QObject *parent)
    : QObject{parent}
{
    qRegisterMetaType<QList<MyBucket> >("QList<MyBucket>");
    qRegisterMetaType<QList<MyObject> >("QList<MyObject>");
}

ManSignals::~ManSignals()
{
    qDebug("delete ManSignals ");
}
