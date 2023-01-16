#include "sortpersons.h"
#include "mainwindow.h"
#include <algorithm>

SortPersons::SortPersons(QWidget *parent) : QMainWindow{parent} {
    sort(MainWindow::telefonbuch.begin(), MainWindow::telefonbuch.end(), [](const MainWindow::Person& a, const MainWindow::Person& b) {
        return a.name < b.name;
    });
    deleteLater();
    destroy();
}
