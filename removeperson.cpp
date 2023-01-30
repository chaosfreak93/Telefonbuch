#include "removeperson.h"
#include "mainwindow.h"

// Constructor for the RemovePerson class
RemovePerson::RemovePerson(QWidget *parent) : QMainWindow{parent} {
    // Create a QListWidget to display a list of people in the telephone book
    list = new QListWidget(this);
    // Set the geometry of the list widget
    list->setGeometry(QRect(50, 15, 300, 240));
    // Loop through each person in the telephone book and add their name, surname, and phone number to the list widget
    for (const auto &person: MainWindow::telefonbuch) {
    list->addItem(person.name + " " + person.surname + ", 0" + QString::number(person.number));
    }
    // Update the list widget
    list->update();

    // Create a remove button
    removeBtn = new QPushButton(this);
    // Set the geometry of the remove button
    removeBtn->setGeometry(QRect(100, 260, 100, 40));
    // Set the text of the remove button
    removeBtn->setText("Remove");

    // Create a cancel button
    cancelBtn = new QPushButton(this);
    // Set the geometry of the cancel button
    cancelBtn->setGeometry(QRect(200, 260, 100, 40));
    // Set the text of the cancel button
    cancelBtn->setText("Cancel");

    // Connect the remove button to the PressedRemoveButton slot
    connect(removeBtn, SIGNAL(clicked()), this, SLOT(PressedRemoveButton()));
    // Connect the cancel button to the PressedCancelButton slot
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(PressedCancelButton()));
}

// The function PressedRemoveButton is a slot that is called when the "Remove" button is clicked.
void RemovePerson::PressedRemoveButton() {
    // Check if there's a current selected item in the list.
    if(list->currentIndex().row() != -1) {
    // If there's a selected item, remove it from the telefonbuch list.
    MainWindow::telefonbuch.removeAt(list->currentIndex().row());
    }
    // Delete the list object.
    list->deleteLater();
    delete list;
    // Delete the removeBtn object.
    removeBtn->deleteLater();
    delete removeBtn;
    // Delete the cancelBtn object.
    cancelBtn->deleteLater();
    delete cancelBtn;
    // Delete the current object.
    deleteLater();
    // Destroys the current object.
    destroy();
}

// This function is triggered when the "Cancel" button is pressed.
void RemovePerson::PressedCancelButton() {
    // Delete the QListWidget object and release its memory.
    list->deleteLater();
    delete list;
    // Delete the "Remove" button object and release its memory.
    removeBtn->deleteLater();
    delete removeBtn;
    // Delete the "Cancel" button object and release its memory.
    cancelBtn->deleteLater();
    delete cancelBtn;
    // Delete the RemovePerson object and release its memory.
    deleteLater();
    destroy();
}
