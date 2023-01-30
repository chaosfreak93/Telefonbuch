#include "mainwindow.h"

QList<MainWindow::Person> MainWindow::telefonbuch{};

// Constructor for the MainWindow class
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create a database manager and set the database file
    db = new DBManager("./telefonbuch.db");

    // Create the telefonbuch table if it does not exist
    db->createTelefonbuchTable();

    // Retrieve the telefonbuch entries from the database
    QSqlQuery query = db->fetchTelefonbuchEntries();
    while (query.next()) {
        telefonbuch.append({query.value(0).toString(), query.value(1).toString(), query.value(2).toLongLong()});
    }

    // Create a button to view telefonbuch entries
    view = new QPushButton(this);
    view->setGeometry(QRect(70, 60, 80, 40));
    view->setText("View Entries");

    // Create a button to sort telefonbuch entries
    sort = new QPushButton(this);
    sort->setGeometry(QRect(150, 60, 80, 40));
    sort->setText("Sort Entries");

    // Create a button to add an entry to the telefonbuch
    add = new QPushButton(this);
    add->setGeometry(QRect(70, 100, 80, 40));
    add->setText("Add Entry");

    // Create a button to remove an entry from the telefonbuch
    remove = new QPushButton(this);
    remove->setGeometry(QRect(150, 100, 80, 40));
    remove->setText("Remove Entry");

    // Connect the view button to the ViewEntries slot
    connect(view, SIGNAL(clicked()), this, SLOT(ViewEntries()));

    // Connect the sort button to the SortEntries slot
    connect(sort, SIGNAL(clicked()), this, SLOT(SortEntries()));

    // Connect the add button to the AddEntry slot
    connect(add, SIGNAL(clicked()), this, SLOT(AddEntry()));

    // Connect the remove button to the RemoveEntry slot
    connect(remove, SIGNAL(clicked()), this, SLOT(RemoveEntry()));
}

// Slot to display the view entries window
void MainWindow::ViewEntries() {
    // Create a ViewPersons object and display it
    viewpersons = new ViewPersons();
    viewpersons->setFocus();
    viewpersons->setFixedSize(400, 300);
    viewpersons->setWindowTitle("View Persons");
    viewpersons->setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    viewpersons->setWindowFlag(Qt::WindowCloseButtonHint, false);
    viewpersons->show();
}

// Slot to sort entries window
void MainWindow::SortEntries() {
    // Create a SortPersons object and display it
    sortperson = new SortPersons();
    sortperson->setFocus();
    sortperson->setFixedSize(400, 300);
    sortperson->setWindowTitle("Sort Persons");
    sortperson->setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    sortperson->setWindowFlag(Qt::WindowCloseButtonHint, false);
    sortperson->show();
}

// Slot to display the add entry window
void MainWindow::AddEntry() {
    // Create a AddPerson object and display it
    addperson = new AddPerson();
    addperson->setFocus();
    addperson->setFixedSize(400, 300);
    addperson->setWindowTitle("Add Person");
    addperson->setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    addperson->setWindowFlag(Qt::WindowCloseButtonHint, false);
    addperson->show();
}

// Slot to display the remove entry window
void MainWindow::RemoveEntry() {
    // Create a RemovePerson object and display it
    removeperson = new RemovePerson();
    removeperson->setFocus();
    removeperson->setFixedSize(400, 300);
    removeperson->setWindowTitle("Remove Person");
    removeperson->setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    removeperson->setWindowFlag(Qt::WindowCloseButtonHint, false);
    removeperson->show();
}

// This function is called whenever the MainWindow is closing.
void MainWindow::closeEvent(QCloseEvent *event) {
    // Ignores the close event so that we can do some necessary actions before closing.
    event->ignore();
    // Saves the telefonbuch to the file.
    db->saveToFile();
    // Accepts the close event so that the MainWindow can finally close.
    event->accept();
}
