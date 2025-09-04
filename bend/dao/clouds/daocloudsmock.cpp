#pragma execution_character_set("utf-8")

#include "DaoCloudsMock.h"
#include "config/BaseException.h"
#include "config/ErrorCode.h"
#include "helper/FileHelper.h"
#include "middle/ManGlobal.h"
#include <QJsonArray>
#include <QThread>
#include "config/Common.h"

DaoCloudsMock::DaoCloudsMock(const QString& path)
{
    m_mock = FileHelper::readAllJson(path).toJsonValue();
}

QList<MyBucket> DaoCloudsMock::buckets()
{
    QList<MyBucket> res;
    QJsonArray arr = m_mock["buckets"].toArray();
    for (int i = 0; i < arr.count(); ++i) {
        QJsonValue v = arr[i];
        MyBucket bucket;
        bucket.name = v["name"].toString();
        bucket.location = v["location"].toString();
        bucket.createDate = v["create_date"].toString();

        res.append(bucket);
        mInfo(STR("name[%1], location[%2], date[%3]").arg(bucket.name, bucket.location, bucket.createDate));
    }

    return res;
}

QList<MyBucket> DaoCloudsMock::login(const QString &secretId, const QString &secretKey)
{
    QJsonArray arr = m_mock["users"].toArray();
    for (int i = 0; i < arr.count(); ++i) {
        QJsonValue v = arr[i];
        if (secretId == v["secretId"].toString() && secretKey == v["secretKey"].toString()) {
            return buckets();
        }
    }
    throw BaseException(EC_211000, STR("请检查您的SecretId或SecretKey是否正确"));
}

bool DaoCloudsMock::isBucketExists(const QString &bucketName)
{
    return false;
}

QString DaoCloudsMock::getBucketLocation(const QString &bucketName)
{
    return QString();
}

void DaoCloudsMock::putBucket(const QString &bucketName, const QString &location)
{

}

void DaoCloudsMock::deleteBucket(const QString &bucketName)
{

}

QList<MyObject> DaoCloudsMock::getObjects(const QString &bucketName, const QString &dir)
{
    return QList<MyObject>();
}

void DaoCloudsMock::putObject(const QString &bucketName, const QString &key, const QString &localPath, const TransProgressCallback &callback)
{

}

void DaoCloudsMock::getObject(const QString &bucketName, const QString &key, const QString &localPath, const TransProgressCallback &callback)
{

}
