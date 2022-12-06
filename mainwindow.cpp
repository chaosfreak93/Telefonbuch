#include "mainwindow.h"

#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    db = new DBManager("C:/Users/leya/OneDrive - SOCITAS GmbH & Co. KG/Desktop/Coden/Telefonbuch/telefonbuch.db");
    db->createTelefonbuchTable();


    view = new QPushButton(this);
    view->setGeometry(QRect(70, 60, 80, 40));
    view->setText("View Entries");

    sort = new QPushButton(this);
    sort->setGeometry(QRect(150, 60, 80, 40));
    sort->setText("Sort Entries");

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
    QString liste;
    QSqlQuery query = db->fetchTelefonbuchEntries();
    while (query.next()) {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString lastname = query.value(2).toString();
        QString number = "0" + query.value(3).toString();
        liste += id + " " + name + " " + lastname + " " + number + ",\n";
    }
    QMessageBox msgBox;
    msgBox.setText(liste);
    msgBox.exec();
}

void MainWindow::SortEntries() {

}

void MainWindow::AddEntry() {
    bool nameOk;
    QString name = QInputDialog::getText(this, tr("Add Entry"),
                                           tr("Name:"), QLineEdit::Normal,
                                           "", &nameOk);
    if (!nameOk || name.isEmpty())
        return;

    bool surnameOk;
    QString surname = QInputDialog::getText(this, tr("Add Entry"),
                                           tr("Surname:"), QLineEdit::Normal,
                                           "", &surnameOk);
    if (!surnameOk || surname.isEmpty())
        return;

    bool numberOk;
    QString number = QInputDialog::getText(this, tr("Add Entry"),
                                           tr("Number:"), QLineEdit::Normal,
                                           "", &numberOk);
    if (!numberOk || number.isEmpty())
        return;

    db->insertEntry(name, surname, number);
}

void MainWindow::RemoveEntry() {
    bool idOk;
    int id = QInputDialog::getInt(this, tr("Remove Entry"),
                                           tr("ID:"), 0, 0, 2147483647, 1,
                                            &idOk);
    if (!idOk)
        return;

    db->deleteById(id);
}
