#include "viewpersons.h"
#include "mainwindow.h"

ViewPersons::ViewPersons(QWidget *parent) : QMainWindow{parent} {
    list = new QListWidget(this);
    list->setGeometry(QRect(50, 15, 300, 240));
    for (const auto &person: MainWindow::telefonbuch) {
        list->addItem(person.name + " " + person.surname + ", 0" + QString::number(person.number));
    }
    list->update();

    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(QRect(150, 260, 100, 40));
    closeBtn->setText("Close");

    connect(closeBtn, SIGNAL(clicked()), this, SLOT(PressedCloseButton()));
}

void ViewPersons::PressedCloseButton() {
    list->deleteLater();
    delete list;
    closeBtn->deleteLater();
    delete closeBtn;
    deleteLater();
    destroy();
}
