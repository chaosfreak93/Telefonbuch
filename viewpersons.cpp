#include "viewpersons.h"
#include "mainwindow.h"

// ViewPersons class constructor: creates the view for all persons in the telephone book
ViewPersons::ViewPersons(QWidget *parent) : QMainWindow{parent} {
    // Create a QListWidget to display the persons in the telephone book
    list = new QListWidget(this);
    // Set the geometry of the list widget to display within the window
    list->setGeometry(QRect(50, 15, 300, 240));
    // Iterate through the persons in the telephone book and add each person's name, surname, and number to the list widget
    for (const auto &person: MainWindow::telefonbuch) {
    list->addItem(person.name + " " + person.surname + ", 0" + QString::number(person.number));
    }
    // Update the list widget
    list->update();

    // Create a close button
    closeBtn = new QPushButton(this);
    // Set the geometry of the close button to display within the window
    closeBtn->setGeometry(QRect(150, 260, 100, 40));
    // Set the text of the close button to "Close"
    closeBtn->setText("Close");

    // Connect the close button to the PressedCloseButton slot
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(PressedCloseButton()));
}

// Slot for the close button: deletes the list widget, close button, and the ViewPersons instance
void ViewPersons::PressedCloseButton() {
    // Delete the list widget
    list->deleteLater();
    delete list;
    // Delete the close button
    closeBtn->deleteLater();
    delete closeBtn;
    // Delete the ViewPersons instance
    deleteLater();
    destroy();
}
