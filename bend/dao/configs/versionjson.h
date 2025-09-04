#pragma once

#include "Version.h"

class VersionJson : public Version
{
public:
    VersionJson(const QString& path);
    void setVersion();

private:
    QString m_path;
};
