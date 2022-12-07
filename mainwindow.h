#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbmanager.h"
#include "addperson.h"
#include "removeperson.h"
#include "viewpersons.h"

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

    struct Person {
        QString name;
        QString surname;
        qlonglong number;
    };

    public:
        MainWindow(QWidget *parent = nullptr);
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

    private slots:
        void ViewEntries();
        void SortEntries();
        void AddEntry();
        void RemoveEntry();
};
#endif // MAINWINDOW_H
