#include "dbmanager.h"

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
    QSqlQuery create;
    create.prepare("CREATE TABLE IF NOT EXISTS telefonbuch(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT(100) NOT NULL, surname TEXT(100) NOT NULL, number BIGINT NOT NULL);");

    if (create.exec()) {
        qDebug() << "Table exists or has been created";
    } else {
        qDebug() << "Table not exists or has not been created";
        qDebug() << "ERROR! " << create.lastError();
    }
}

QSqlQuery DBManager::fetchTelefonbuchEntries() {
    QSqlQuery select;
    select.prepare("SELECT * FROM telefonbuch;");

    if (select.exec()) {
        qDebug() << "Data has been selected";
    } else {
        qDebug() << "Data cannot be selected";
        qDebug() << "ERROR! " << select.lastError();
    }
    return select;
}
