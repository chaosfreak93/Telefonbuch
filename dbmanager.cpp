#include "dbmanager.h"
#include "mainwindow.h"

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
    create.prepare("CREATE TABLE IF NOT EXISTS telefonbuch(id INTEGER PRIMARY KEY, name TEXT(100) NOT NULL, surname TEXT(100) NOT NULL, number BIGINT NOT NULL);");

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

void DBManager::saveToFile() {
    QSqlQuery drop;
    drop.prepare("DELETE FROM telefonbuch;");
    if(drop.exec()) qDebug() << "Table cleared";

    for (int i = 0; i < MainWindow::telefonbuch.size(); i++) {
        QSqlQuery insert;
        insert.prepare("INSERT INTO telefonbuch (id, name, surname, number) VALUES (?, ?, ?, ?);");
        insert.addBindValue(i);
        insert.addBindValue(MainWindow::telefonbuch[i].name);
        insert.addBindValue(MainWindow::telefonbuch[i].surname);
        insert.addBindValue(MainWindow::telefonbuch[i].number);
        if(insert.exec()) qDebug() << "Data inserted";
    }
}
