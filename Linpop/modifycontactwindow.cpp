#include "modifycontactwindow.h"
#include "ui_modifycontactwindow.h"
#include <iostream>

ModifyContactWindow::ModifyContactWindow(ContactWindow *_cw, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModifyContactWindow)
{
    ui->setupUi(this);
    this->cw = _cw;
    ui->user_name->setText(this->cw->getName());
    ui->ip->setText(this->cw->getIp());

}

ModifyContactWindow::~ModifyContactWindow()
{
    delete ui;
}

void ModifyContactWindow::on_modify_clicked()
{
    this->cw->setContact(ui->user_name->text(), ui->ip->text());
    this->close();
}
