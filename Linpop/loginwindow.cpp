#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->InitLogin();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_bConnexion_clicked()
{
    QString name = ui->user_name->text();
    QString pwd = ui->password->text();

    if (db->getUser(name, pwd) != NULL)
        OpenContactWindow();
    else
        QMessageBox::warning(this, "User doesn't exist", "Unable to connect. User doesn't exist.");


}

void LoginWindow::on_bCreateAccount_clicked()
{
    QString name = ui->user_name->text();
    QString pwd = ui->password->text();

    if (name == "")
        QMessageBox::warning(this, "Name invalid", "Unable to create user. You should put a name.");
    else if (pwd == "")
        QMessageBox::warning(this, "Password invalid", "Unable to create user. You should put a password.");
    else if (db->getUser(name, pwd) == NULL)
    {
        User u(name, pwd);
        if (db->addUser(u) != 1)
            OpenContactWindow();
        else
            QMessageBox::warning(this, "Unable to create user", "Unable to create user. Problem with database.");
    } 
    else
        QMessageBox::warning(this, "User already exist", "Unable to create user. User already exist.");

}

void    LoginWindow::InitLogin()
{
    //Initialise les ptr
    QString path = "./../bdd_linpop.db";
    this->no = new NetworkObject;
    this->cw = new ContactWindow(no);
    no->setContactWindow(this->cw);
    this->no->initialize(5000);
    this->db = new Database(path);
    db->openDatabase();
    ui->password->setEchoMode(QLineEdit::Password);
}

void    LoginWindow::OpenContactWindow()
{
    cw->setLoginWindow(this);
    cw->initContactWindow(this->db, ui->user_name->text(), ui->password->text());
    this->hide();
    db->closeDatabase();
    cw->show();
}
