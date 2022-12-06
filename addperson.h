#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QMainWindow>
#include <QPushButton>

using namespace std;

class AddPerson : public QMainWindow {
    Q_OBJECT
    public:
        explicit AddPerson(QWidget *parent = nullptr);
        QPushButton* closeBtn;

    private slots:
        void CloseWindow();
};

#endif // ADDPERSON_H
