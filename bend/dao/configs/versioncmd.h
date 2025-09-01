#pragma once

#include "version.h"
#include <QStringList>

class VersionCmd : public Version
{
public:
    VersionCmd(int argc, char *argv[]);

    void setVersion();
    bool isValid();

private:
    QStringList m_argv;
};
