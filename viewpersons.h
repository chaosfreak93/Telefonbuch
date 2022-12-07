#ifndef VIEWPERSONS_H
#define VIEWPERSONS_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>

class ViewPersons : public QMainWindow {
    Q_OBJECT

    public:
        explicit ViewPersons(QWidget *parent = nullptr);

    private:
        QListWidget* list;
        QPushButton* closeBtn;

    private slots:
        void PressedCloseButton();
};

#endif // VIEWPERSONS_H
