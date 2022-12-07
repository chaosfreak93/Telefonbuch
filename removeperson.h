#ifndef REMOVEPERSON_H
#define REMOVEPERSON_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>

using namespace std;

class RemovePerson : public QMainWindow {
    Q_OBJECT

    public:
        explicit RemovePerson(QWidget *parent = nullptr);
        QListWidget* list;
        QPushButton* removeBtn;
        QPushButton* cancelBtn;

    private slots:
        void PressedRemoveButton();
        void PressedCancelButton();
};

#endif // REMOVEPERSON_H
