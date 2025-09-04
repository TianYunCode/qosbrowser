#pragma execution_character_set("utf-8")

#include "FileHelper.h"

#include <QFile>
#include <QJsonDocument>
#include <QDir>
#include <QRegularExpression>

FileHelper::FileHelper()
{

}

QString FileHelper::readAllTxt(const QString &filePath)
{
    QFile file(filePath);
    if (file.exists() && file.open(QIODevice::ReadOnly))
    {
        QByteArray data = file.readAll();
        file.close();
        return data;
    }
    throw "读取文件失败";
}

QVariant FileHelper::readAllJson(const QString &filePath)
{
    QString data = FileHelper::readAllTxt(filePath);
    QJsonDocument doc = QJsonDocument::fromJson(data.toLocal8Bit());
    return doc.toVariant();
}

QList<QStringList> FileHelper::readAllCsv(const QString &filePath)
{
    QList<QStringList> records;
    QFile file(filePath);
    if (file.exists() && file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList row = line.split(',');
            records.append(row);
        }

        file.close();
    }

    return records;
}

void FileHelper::generateExceptionFile(const QString &filePath)
{

}

void FileHelper::writeFlie(const QStringList lines, const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        // Qt 5 及更早版本
        stream.setCodec("UTF-8");
#else
        // Qt 6 及更新版本
        stream.setEncoding(QStringConverter::Utf8);
#endif

        for(const auto& line: lines) {

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
            stream << line << endl; // Qt 5
#else
            stream << line << Qt::endl; // Qt 6
#endif
        }
        file.close();
        return;
    }
    throw "写入文件失败";
}


QString FileHelper::joinPath(const QString &path1, const QString &path2)
{
    QString path = path1 + "/" + path2;
    QStringList pathList = path.split(QRegularExpression ("[/\\\\]"), Qt::SkipEmptyParts);
    path = pathList.join("/");
    return QDir::cleanPath(path);
}

bool FileHelper::mkPath(const QString &path)
{
    QDir dir;
    return dir.mkpath(path);
}
