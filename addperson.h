#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

using namespace std;

class AddPerson : public QMainWindow {
    Q_OBJECT
    public:
        explicit AddPerson(QWidget *parent = nullptr);

    private:
        QLineEdit* name;
        QLineEdit* surname;
        QLineEdit* number;
        QPushButton* addBtn;
        QPushButton* cancelBtn;

    private slots:
        void PressedAddButton();
        void PressedCancelButton();
};

#endif // ADDPERSON_H
