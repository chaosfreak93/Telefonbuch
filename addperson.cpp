#include "addperson.h"

AddPerson::AddPerson(QWidget *parent) : QMainWindow{parent} {
    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(QRect(160, 260, 80, 40));
    closeBtn->setText("Close (Add)");

    connect(closeBtn, SIGNAL(clicked()), this, SLOT(CloseWindow()));

    //TODO: Add Input Fields
}

void AddPerson::CloseWindow() {
    close();
}
