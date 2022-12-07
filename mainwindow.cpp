#include "mainwindow.h"

QList<MainWindow::Person> MainWindow::telefonbuch{};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    db = new DBManager("./telefonbuch.db");
    db->createTelefonbuchTable();
    QSqlQuery query = db->fetchTelefonbuchEntries();
    while (query.next()) {
        telefonbuch.append({query.value(0).toString(), query.value(1).toString(), query.value(2).toLongLong()});
    }

    view = new QPushButton(this);
    view->setGeometry(QRect(70, 60, 80, 40));
    view->setText("View Entries");

    sort = new QPushButton(this);
    sort->setGeometry(QRect(150, 60, 80, 40));
    sort->setText("Sort Entries");
    sort->setDisabled(true);

    add = new QPushButton(this);
    add->setGeometry(QRect(70, 100, 80, 40));
    add->setText("Add Entry");

    remove = new QPushButton(this);
    remove->setGeometry(QRect(150, 100, 80, 40));
    remove->setText("Remove Entry");

    connect(view, SIGNAL(clicked()), this, SLOT(ViewEntries()));
    connect(sort, SIGNAL(clicked()), this, SLOT(SortEntries()));
    connect(add, SIGNAL(clicked()), this, SLOT(AddEntry()));
    connect(remove, SIGNAL(clicked()), this, SLOT(RemoveEntry()));
}

void MainWindow::ViewEntries() {
    viewpersons = new ViewPersons();
    viewpersons->setFocus();
    viewpersons->setFixedSize(400, 300);
    viewpersons->setWindowTitle("View Persons");
    viewpersons->setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    viewpersons->setWindowFlag(Qt::WindowCloseButtonHint, false);
    viewpersons->show();
}

void MainWindow::SortEntries() {

}

void MainWindow::AddEntry() {
    addperson = new AddPerson();
    addperson->setFocus();
    addperson->setFixedSize(400, 300);
    addperson->setWindowTitle("Add Person");
    addperson->setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    addperson->setWindowFlag(Qt::WindowCloseButtonHint, false);
    addperson->show();
}

void MainWindow::RemoveEntry() {
    removeperson = new RemovePerson();
    removeperson->setFocus();
    removeperson->setFixedSize(400, 300);
    removeperson->setWindowTitle("Remove Person");
    removeperson->setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    removeperson->setWindowFlag(Qt::WindowCloseButtonHint, false);
    removeperson->show();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    event->ignore();
    db->saveToFile();
    event->accept();
}
