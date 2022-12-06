#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <iostream>
#include <QSqlDatabase>
#include <QSqlResult>

using namespace std;

class DBManager {
    public:
        DBManager(const QString& path);
        void createTelefonbuchTable();
        QSqlQuery fetchTelefonbuchEntries();
        void insertEntry(QString name, QString surname, QString number);
        void deleteById(int id);

    private:
        QSqlDatabase db;
};
#endif // DBMANAGER_H
