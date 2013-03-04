#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "contactwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

    //DatabaseObject    *db
    ContactWindow     *cw;
    //NetworkServer     *ns

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

    void InitLogin();
    void OpenContactWindow();

private slots:
    void on_bConnexion_clicked();

    void on_bCreateAccount_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
