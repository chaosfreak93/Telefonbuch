#ifndef REMOVEPERSON_H
#define REMOVEPERSON_H

#include <QMainWindow>
#include <QPushButton>

using namespace std;

class RemovePerson : public QMainWindow {
    Q_OBJECT

    public:
        explicit RemovePerson(QWidget *parent = nullptr);
        QPushButton* closeBtn;

    private slots:
        void CloseWindow();
};

#endif // REMOVEPERSON_H
