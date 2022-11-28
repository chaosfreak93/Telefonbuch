#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <iostream>
#include <QSqlDatabase>

using namespace std;

class DBManager {
    public:
        DBManager(const QString& path);
        void createTelefonbuchTable();
    private:
        QSqlDatabase db;
};
#endif // DBMANAGER_H
