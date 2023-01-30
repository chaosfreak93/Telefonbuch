#include "dbmanager.h"
#include "mainwindow.h"

// Constructor of the DBManager class, sets the database path and opens the connection to it.
DBManager::DBManager(const QString& path) {
    // Create a SQLite database connection
    db = QSqlDatabase::addDatabase("QSQLITE");
    // Set the database name to the path passed to the constructor
    db.setDatabaseName(path);

    // Try to open the database
    if (!db.open()) {
    // If the connection failed, print an error message to the debug output
    qDebug() << "Error: connection with database failed";
    } else {
    // If the connection was successful, print a message to the debug output
    qDebug() << "Database: connection ok";
    }
}

// Function to create telefonbuch table in database
void DBManager::createTelefonbuchTable() {
    QSqlQuery create;
    // Prepare query to create table if it doesn't exist
    create.prepare("CREATE TABLE IF NOT EXISTS telefonbuch(id INTEGER PRIMARY KEY, name TEXT(100) NOT NULL, surname TEXT(100) NOT NULL, number BIGINT NOT NULL);");

    // Execute query
    if (create.exec()) {
        qDebug() << "Table exists or has been created";
    } else {
        qDebug() << "Table not exists or has not been created";
        qDebug() << "ERROR! " << create.lastError();
    }
}

// Function to fetch telefonbuch entries from the database
QSqlQuery DBManager::fetchTelefonbuchEntries() {
    QSqlQuery select;
    // Prepare a SELECT statement to get the data from the telefonbuch table
    select.prepare("SELECT name, surname, number FROM telefonbuch;");

    // If the SELECT statement is executed successfully
    if (select.exec()) {
        // Print a message indicating the data has been selected
        qDebug() << "Data has been selected";
    } else {
        // If the SELECT statement fails, print an error message
        qDebug() << "Data cannot be selected";
        qDebug() << "ERROR! " << select.lastError();
    }
    // Return the QSqlQuery object containing the result of the SELECT statement
    return select;
}

void DBManager::saveToFile() {
    // Prepare the DELETE statement to clear the telefonbuch table
    QSqlQuery drop;
    drop.prepare("DELETE FROM telefonbuch;");
    if(drop.exec()) {
        // Success message for clearing the table
        qDebug() << "Table cleared";
    }

    // Loop through all the entries in MainWindow::telefonbuch
    for (int i = 0; i < MainWindow::telefonbuch.size(); i++) {
        // Prepare the INSERT statement for adding new entries to the telefonbuch table
        QSqlQuery insert;
        insert.prepare("INSERT INTO telefonbuch (id, name, surname, number) VALUES (?, ?, ?, ?);");
        // Bind values to the statement
        insert.addBindValue(i);
        insert.addBindValue(MainWindow::telefonbuch[i].name);
        insert.addBindValue(MainWindow::telefonbuch[i].surname);
        insert.addBindValue(MainWindow::telefonbuch[i].number);
        // Execute the statement
        if(insert.exec()) {
            // Success message for adding data to the table
            qDebug() << "Data inserted";
        }
    }
}
