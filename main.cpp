#include "mainwindow.h"

#include <QApplication>

// Main function of the GUI application
int main(int argc, char *argv[]) {
    // Create the application object
    QApplication a(argc, argv);

    // Create the main window widget
    MainWindow w;

    // Give focus to the main window
    w.setFocus();

    // Set fixed size for the main window
    w.setFixedSize(300, 200);

    // Set title for the main window
    w.setWindowTitle("Telefonbuch");

    // Show the main window
    w.show();

    // Start the application's event loop
    return a.exec();
}
