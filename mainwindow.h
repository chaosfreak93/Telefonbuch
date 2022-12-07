#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbmanager.h"
#include "addperson.h"
#include "removeperson.h"

#include <QMainWindow>
#include <QPushButton>
#include <QList>
#include <QString>
#include <QMessageBox>
#include <QInputDialog>
#include <QCloseEvent>
#include <QSqlQuery>
#include <QDebug>

using namespace std;

class MainWindow : public QMainWindow {
    Q_OBJECT

    struct Person {
        int id;
        QString name;
        QString surname;
        qlonglong number;
    };

    public:
        MainWindow(QWidget *parent = nullptr);
        static QList<Person> telefonbuch;

    private:
        DBManager* db;
        QPushButton* view;
        QPushButton* sort;
        QPushButton* add;
        QPushButton* remove;
        QPushButton* exit;
        AddPerson* addperson;
        RemovePerson* removeperson;

    private slots:
        void ViewEntries();
        void SortEntries();
        void AddEntry();
        void RemoveEntry();
};
#endif // MAINWINDOW_H
