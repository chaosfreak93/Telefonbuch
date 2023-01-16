#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbmanager.h"
#include "addperson.h"
#include "removeperson.h"
#include "viewpersons.h"
#include "sortpersons.h"

#include <QMainWindow>
#include <QPushButton>
#include <QList>
#include <QString>
#include <QCloseEvent>
#include <QSqlQuery>
#include <QDebug>

using namespace std;

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        struct Person {
            QString name;
            QString surname;
            qlonglong number;
        };
        static QList<Person> telefonbuch;
        void closeEvent(QCloseEvent *event);

    private:
        DBManager* db;
        QPushButton* view;
        QPushButton* sort;
        QPushButton* add;
        QPushButton* remove;
        QPushButton* exit;
        AddPerson* addperson;
        RemovePerson* removeperson;
        ViewPersons* viewpersons;
        SortPersons* sortperson;

    private slots:
        void ViewEntries();
        void SortEntries();
        void AddEntry();
        void RemoveEntry();
};
#endif // MAINWINDOW_H
