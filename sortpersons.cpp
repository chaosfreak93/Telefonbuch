#include "sortpersons.h"
#include "mainwindow.h"
#include <algorithm>

//SortPersons constructor
SortPersons::SortPersons(QWidget *parent) : QMainWindow{parent} {
    //Sort the telefonbuch by name using the STL sort algorithm and a lambda function
    sort(MainWindow::telefonbuch.begin(), MainWindow::telefonbuch.end(), [](const MainWindow::Person& a, const MainWindow::Person& b) {
    return a.name < b.name;
    });
    //Delete the current object and frees its resources
    deleteLater();
    destroy();
}
