#include "contextualmenupopup.h"
#include "ui_contextualmenupopup.h"
#include <QMenu>
#include <iostream>
#include "modifycontactwindow.h"

ContextualMenuPopup::ContextualMenuPopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContextualMenuPopup)
{
    ui->setupUi(this);
}

void    ContextualMenuPopup::InitMenu(QPoint globalpos, ContactWindow *_cw)
{
    this->cw = _cw;
    QMenu menu(this->cw);

    this->history = new QAction("History", this);
    menu.addAction(this->history);
    this->setting = new QAction("Setting", this);
    menu.addAction(this->setting);
    this->del = new QAction("Delete", this);
    menu.addAction(this->del);
    connect(this->history, SIGNAL(triggered()), this, SLOT(History()));
    connect(this->setting, SIGNAL(triggered()), this, SLOT(SetContact()));
    connect(this->del, SIGNAL(triggered()), this, SLOT(DeleteContact()));
    menu.exec(globalpos);
}

void    ContextualMenuPopup::History()
{
    std::cout << "History" << std::endl;
}

void    ContextualMenuPopup::SetContact()
{
    ModifyContactWindow *mcw = new ModifyContactWindow(this->cw);

    mcw->show();
}

void    ContextualMenuPopup::DeleteContact()
{
    this->cw->deleteContact();
}

ContextualMenuPopup::~ContextualMenuPopup()
{
    delete ui;
}
