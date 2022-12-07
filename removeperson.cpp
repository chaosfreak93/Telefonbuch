#include "removeperson.h"
#include "mainwindow.h"

RemovePerson::RemovePerson(QWidget *parent) : QMainWindow{parent} {
    list = new QListWidget(this);
    list->setGeometry(QRect(50, 15, 300, 240));
    for (int i = 0; i < MainWindow::telefonbuch.size(); i++) {
        list->addItem(MainWindow::telefonbuch[i].name + " " + MainWindow::telefonbuch[i].surname + ", 0" + QString::number(MainWindow::telefonbuch[i].number));
    }
    list->update();

    removeBtn = new QPushButton(this);
    removeBtn->setGeometry(QRect(100, 260, 100, 40));
    removeBtn->setText("Remove");

    cancelBtn = new QPushButton(this);
    cancelBtn->setGeometry(QRect(200, 260, 100, 40));
    cancelBtn->setText("Cancel");

    connect(removeBtn, SIGNAL(clicked()), this, SLOT(PressedRemoveButton()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(PressedCancelButton()));
}

void RemovePerson::PressedRemoveButton() {
    if(list->currentIndex().row() != -1) {
        MainWindow::telefonbuch.removeAt(list->currentIndex().row());
    }
    list->clear();
    list = nullptr;
    removeBtn = nullptr;
    cancelBtn = nullptr;
    close();
    destroy();
}

void RemovePerson::PressedCancelButton() {
    list->clear();
    list = nullptr;
    removeBtn = nullptr;
    cancelBtn = nullptr;
    close();
    destroy();
}
