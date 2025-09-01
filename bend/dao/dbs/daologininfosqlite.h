#pragma once

#include "daologininfo.h"

class DaoLoginInfoSqlite: public DaoLoginInfo
{
public:
    DaoLoginInfoSqlite();

    bool exists(const QString& secretId);
    void insert(const LoginInfo& info);
    void update(const LoginInfo& info);
    void remove(const QString& secretId);
    QList<LoginInfo> select();

    void connect();
    void createTable();

private:
    DbSqlite m_db;
};
