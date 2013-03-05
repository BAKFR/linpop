#ifndef MODIFYCONTACTWINDOW_H
#define MODIFYCONTACTWINDOW_H

#include <QMainWindow>
#include "contactwindow.h"

namespace Ui {
class ModifyContactWindow;
}

class ModifyContactWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ModifyContactWindow(ContactWindow *cw, QWidget *parent = 0);
    ~ModifyContactWindow();
    
private slots:
    void on_modify_clicked();

private:
    Ui::ModifyContactWindow *ui;
    ContactWindow *cw;
};

#endif // MODIFYCONTACTWINDOW_H
