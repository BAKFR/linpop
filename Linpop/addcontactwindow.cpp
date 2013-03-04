#include "addcontactwindow.h"
#include "ui_addcontactwindow.h"
#include <iostream>

AddContactWindow::AddContactWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddContactWindow)
{
    ui->setupUi(this);
}

AddContactWindow::~AddContactWindow()
{
    delete ui;
}

void AddContactWindow::setContactWindow(ContactWindow *_cw)
{
    cw = _cw;
}


void AddContactWindow::on_addContact_clicked()
{
    //Insérer le nouveau contact en bdd et dans la liste contact
    cw->addContact(ui->user_name->text(), ui->ip->text());
    this->close();
}

