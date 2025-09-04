#pragma execution_character_set("utf-8")

#include "ManPlugin.h"
#include "bend/dao/clouds/DaoCloudsMock.h"
#include "bend/dao/configs/VersionCmd.h"
#include "bend/dao/configs/VersionJson.h"
#include "config/GLOBAL.h"
#include "middle/ManGlobal.h"
#include "bend/dao/logs/LoggerQDebug.h"

#include <bend/dao/clouds/DaoCloudsCos.h>
using namespace GLOBAL;


ManPlugin::ManPlugin(QObject *parent)
    : QObject{parent}
{

}

ManPlugin::~ManPlugin()
{
    delete m_clouds;
    delete m_version;
    qDebug("delete ManPlugins ");
}

void ManPlugin::installPlugins(int argc, char *argv[])
{
    // 如果输入命令行，则命令行参数优先级最高，否则直接加载配置文件中的配置信息
    VersionCmd version(argc, argv);
    if (version.isValid()){
        m_version = new VersionCmd(argc, argv);
    }
    else {
        m_version = new VersionJson(VERSION::JSON_PATH);
    }
    m_version->setVersion();

    // 安装日志插件
    mLogIns->setLogger(new LoggerQDebug());
//    mlog->setLevel(GLOBAL::LOG_LEVEL::INFO);

    // 安装云存储插件
    if (m_version->major() == VERSION::MAJOR_BUSINESS){
        m_clouds = new DaoCloudsCos();
    }
    else {
        m_clouds = new DaoCloudsMock(":/resource/testing/custom.json");
    }
}

DaoClouds *ManPlugin::clouds() const
{
    return m_clouds;
}
