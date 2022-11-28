#include "mainwindow.h"
#include "dbmanager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    DBManager db("telefonbuch.db");
    db.createTelefonbuchTable();
}
