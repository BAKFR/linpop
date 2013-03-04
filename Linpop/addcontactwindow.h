#ifndef ADDCONTACTWINDOW_H
#define ADDCONTACTWINDOW_H

#include <QMainWindow>
#include "contactwindow.h"

namespace Ui {
class AddContactWindow;
}

class AddContactWindow : public QMainWindow
{
    Q_OBJECT
    ContactWindow    *cw;

public:
    explicit AddContactWindow(QWidget *parent = 0);
    ~AddContactWindow();

    void setContactWindow(ContactWindow *);

private slots:
    void on_addContact_clicked();

private:
    Ui::AddContactWindow *ui;


};

#endif // ADDCONTACTWINDOW_H
