#include "removeperson.h"

RemovePerson::RemovePerson(QWidget *parent) : QMainWindow{parent} {
    closeBtn = new QPushButton(this);
    closeBtn->setGeometry(QRect(150, 260, 100, 40));
    closeBtn->setText("Close (Remove)");

    connect(closeBtn, SIGNAL(clicked()), this, SLOT(CloseWindow()));

    //TODO: List Select
}

void RemovePerson::CloseWindow() {
    close();
}
