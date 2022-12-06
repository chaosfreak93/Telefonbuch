#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <iostream>
#include <QSqlDatabase>
#include <QSqlResult>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>

using namespace std;

class DBManager {
    public:
        DBManager(const QString& path);
        void createTelefonbuchTable();
        QSqlQuery fetchTelefonbuchEntries();

    private:
        QSqlDatabase db;
};
#endif // DBMANAGER_H
