#include "addperson.h"
#include "mainwindow.h"

// Constructor for the AddPerson class, which is a subclass of QMainWindow
AddPerson::AddPerson(QWidget *parent) : QMainWindow{parent} {
    // Creates a new QLineEdit widget to accept the name of a person
    name = new QLineEdit(this);
    // Sets the geometry of the name widget
    name->setGeometry(QRect(125, 50, 150, 30));
    // Sets a placeholder text for the name widget
    name->setPlaceholderText("Enter Name");

    // Creates a new QLineEdit widget to accept the surname of a person
    surname = new QLineEdit(this);
    // Sets the geometry of the surname widget
    surname->setGeometry(QRect(125, 100, 150, 30));
    // Sets a placeholder text for the surname widget
    surname->setPlaceholderText("Enter Surname");

    // Creates a new QLineEdit widget to accept the phone number of a person
    number = new QLineEdit(this);
    // Sets the geometry of the phone number widget
    number->setGeometry(QRect(125, 150, 150, 30));
    // Sets a placeholder text for the phone number widget
    number->setPlaceholderText("Enter Number");

    // Creates a new QPushButton widget for the "Add" button
    addBtn = new QPushButton(this);
    // Sets the geometry of the "Add" button widget
    addBtn->setGeometry(QRect(100, 260, 100, 40));
    // Sets the text of the "Add" button widget
    addBtn->setText("Add");

    // Creates a new QPushButton widget for the "Cancel" button
    cancelBtn = new QPushButton(this);
    // Sets the geometry of the "Cancel" button widget
    cancelBtn->setGeometry(QRect(200, 260, 100, 40));
    // Sets the text of the "Cancel" button widget
    cancelBtn->setText("Cancel");

    // Connects the "Add" button's "clicked" signal to the "PressedAddButton" slot
    connect(addBtn, SIGNAL(clicked()), this, SLOT(PressedAddButton()));
    // Connects the "Cancel" button's "clicked" signal to the "PressedCancelButton" slot
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(PressedCancelButton()));
}

/*
  This function PressedAddButton() is triggered when the "Add" button is pressed.
  It checks if the name, surname, and number fields are not empty and the number entered is greater than 0.
  If the check is successful, the name, surname, and number information is appended to the telefonbuch.
  Then, all the UI elements (name, surname, number, addBtn, cancelBtn) are deleted.
*/
void AddPerson::PressedAddButton() {
    if (!name->text().isEmpty() && !surname->text().isEmpty() && (!number->text().isEmpty() && number->text().toLongLong() > 0)) {
        MainWindow::telefonbuch.append({name->text(), surname->text(), number->text().toLongLong()});
        name->deleteLater();
        delete name;
        surname->deleteLater();
        delete surname;
        number->deleteLater();
        delete number;
        addBtn->deleteLater();
        delete addBtn;
        cancelBtn->deleteLater();
        delete cancelBtn;
        deleteLater();
        destroy();
    }
}

// The following function is called when the "Cancel" button is pressed
void AddPerson::PressedCancelButton() {
    // Delete the "name" widget
    name->deleteLater();
    delete name;
    // Delete the "surname" widget
    surname->deleteLater();
    delete surname;
    // Delete the "number" widget
    number->deleteLater();
    delete number;
    // Delete the "addBtn" widget
    addBtn->deleteLater();
    delete addBtn;
    // Delete the "cancelBtn" widget
    cancelBtn->deleteLater();
    delete cancelBtn;
    // Delete the object
    deleteLater();
    // Destroy the object
    destroy();
}
