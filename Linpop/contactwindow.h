#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QMainWindow>

namespace Ui {
class ContactWindow;
}

class ContactWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ContactWindow(QWidget *parent = 0);
    ~ContactWindow();
    
private:
    Ui::ContactWindow *ui;
};

#endif // CONTACTWINDOW_H
