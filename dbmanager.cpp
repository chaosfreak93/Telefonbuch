#include "dbmanager.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>

DBManager::DBManager(const QString& path) {
   db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName(path);

   if (!db.open()) {
      qDebug() << "Error: connection with database failed";
   } else {
      qDebug() << "Database: connection ok";
   }
}

void DBManager::createTelefonbuchTable() {
    QString query;
    query.append("CREATE TABLE IF NOT EXISTS telefonbuch("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "name VARCHAR(100),"
                    "surname VARCHAR(100),"
                    "number INTEGER NOT NULL,"
                    ");");

    QSqlQuery create;
    create.prepare(query);

    if (create.exec()) {
        qDebug() << "Table exists or has been created";
    } else {
        qDebug() << "Table not exists or has not been created";
        qDebug() << "ERROR! " << create.lastError();
    }
}
