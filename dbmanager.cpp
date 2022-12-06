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
    QSqlQuery create;
    create.prepare("CREATE TABLE IF NOT EXISTS telefonbuch(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT(100), surname TEXT(100), number BIGINT NOT NULL);");

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

void DBManager::insertEntry(QString name, QString surname, QString number) {
    QSqlQuery insert;
    insert.prepare("INSERT INTO telefonbuch (name, surname, number) VALUES(?, ?, ?);");
    insert.addBindValue(name);
    insert.addBindValue(surname);
    insert.addBindValue(number.toLongLong());

    if(insert.exec()){
        qDebug() << "New Entry inserted";
    } else {
        qDebug() << "Entry cannot be inserted";
        qDebug() << "ERROR! " << insert.lastError();
    }
}

void DBManager::deleteById(int id) {
    QSqlQuery remove;
    remove.prepare("DELETE FROM telefonbuch WHERE id = ?;");
    remove.addBindValue(id);

    if(remove.exec()){
        qDebug() << "Entry deleted";
    } else {
        qDebug() << "Entry cannot be deleted";
        qDebug() << "ERROR! " << remove.lastError();
    }
}
