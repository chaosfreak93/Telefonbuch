#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QPushButton>
#include <QSqlQuery>
#include "dbmanager.h"

using namespace std;

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        QPushButton* view;
        QPushButton* sort;
        QPushButton* add;
        QPushButton* remove;
        QPushButton* exit;

    private:
        DBManager* db;

    private slots:
        void ViewEntries();
        void SortEntries();
        void AddEntry();
        void RemoveEntry();
};
#endif // MAINWINDOW_H
