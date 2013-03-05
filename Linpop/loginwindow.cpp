#include "loginwindow.h"
#include "ui_loginwindow.h"

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
    //Click sur Connexion
    //if (db->getUser() == -1)
        //Erreur
    //else
    OpenContactWindow();
}

void LoginWindow::on_bCreateAccount_clicked()
{
    //Click sur new account
    //if (db->getIdUser() == -1)
   // {
        //db->addUser(ui->user_name->text(), ui->password->text());
        OpenContactWindow();
    //}
      //  else error
}

void    LoginWindow::InitLogin()
{
    //Initialise les ptr
    //this->db = new Database;
    this->no = new NetworkObject;
    this->cw = new ContactWindow(no);
    no->setContactWindow(this->cw);
    this->no->initialize(5000);
    //this->db = new Database("linpop_bdd_test", "", "", 1);
    //db->openDatabase();
    //Masque l'affichage du champ password
    ui->password->setEchoMode(QLineEdit::Password);
}

void    LoginWindow::OpenContactWindow()
{
    cw->setLoginWindow(this);
    this->hide();
    cw->show();
}
