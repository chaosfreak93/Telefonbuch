#include "addperson.h"
#include "mainwindow.h"

AddPerson::AddPerson(QWidget *parent) : QMainWindow{parent} {
    name = new QLineEdit(this);
    name->setGeometry(QRect(125, 50, 150, 30));
    name->setPlaceholderText("Enter Name");

    surname = new QLineEdit(this);
    surname->setGeometry(QRect(125, 100, 150, 30));
    surname->setPlaceholderText("Enter Surname");


    number = new QLineEdit(this);
    number->setGeometry(QRect(125, 150, 150, 30));
    number->setPlaceholderText("Enter Number");

    addBtn = new QPushButton(this);
    addBtn->setGeometry(QRect(100, 260, 100, 40));
    addBtn->setText("Add");

    cancelBtn = new QPushButton(this);
    cancelBtn->setGeometry(QRect(200, 260, 100, 40));
    cancelBtn->setText("Cancel");

    connect(addBtn, SIGNAL(clicked()), this, SLOT(PressedAddButton()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(PressedCancelButton()));
}

void AddPerson::PressedAddButton() {
    if (!name->text().isEmpty() && !surname->text().isEmpty() && (!number->text().isEmpty() && number->text().toLongLong() > 0)) {
        MainWindow::telefonbuch.append({name->text(), surname->text(), number->text().toLongLong()});
        close();
        destroy();
    }
}

void AddPerson::PressedCancelButton() {
    close();
    destroy();
}
