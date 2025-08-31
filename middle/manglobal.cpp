#pragma execution_character_set("utf-8")

#include <QApplication>

#include "manglobal.h"
#include "bend/gateway.h"
#include "middle/manmodels.h"
#include "middle/signals/mansignals.h"
#include "plugins/manplugin.h"

#include <bend/man/mancloud.h>
#include <bend/man/mandb.h>

Q_GLOBAL_STATIC(ManGlobal, ins)

ManGlobal::ManGlobal(QObject *parent)
    : QObject{parent}
{
    mLog = new LoggerProxy(this);
    mCloud = new ManCloud(this);
    mDb = new ManDB(this);
    mSignal = new ManSignals(this);
    mPlugin = new ManPlugin(this);
    mGate = new GateWay(this);
//    mModels = new ManModels(this);
}

ManGlobal::~ManGlobal()
{
    qDebug("delete ManGlobal ");
}

ManGlobal *ManGlobal::instance()
{
    return ins();
}

void ManGlobal::init(int argc, char *argv[])
{
    mModels = new ManModels(this);
    FileHelper::mkPath(GLOBAL::PATH::LOG_DIR);
    FileHelper::mkPath(GLOBAL::PATH::TMP);

    mPlugin->installPlugins(argc, argv);

    QString qssStr = FileHelper::readAllTxt(":/resource/qss/default.qss");
    qApp->setStyleSheet(qssStr);

    mDb->init();
}
