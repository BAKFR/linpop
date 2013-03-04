#include "contextualmenupopup.h"
#include "ui_contextualmenupopup.h"
#include <QMenu>
#include <iostream>

ContextualMenuPopup::ContextualMenuPopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContextualMenuPopup)
{
    ui->setupUi(this);
}

void    ContextualMenuPopup::InitMenu(QPoint globalpos, QWidget *cw)
{
    QMenu menu(cw);

    this->history = new QAction("History", this);
    menu.addAction(this->history);
    this->setting = new QAction("Setting", this);
    menu.addAction(this->setting);
    this->del = new QAction("Delete", this);
    menu.addAction(this->del);
    connect(this->history, SIGNAL(triggered()), this, SLOT(History()));
    connect(this->setting, SIGNAL(triggered()), this, SLOT(SetContact()));
    connect(this->setting, SIGNAL(triggered()), this, SLOT(DeleteContact()));
    menu.exec(globalpos);
}

void    ContextualMenuPopup::History()
{
    std::cout << "History" << std::endl;
}

void    ContextualMenuPopup::SetContact()
{
    std::cout << "Contact" << std::endl;
}

void    ContextualMenuPopup::DeleteContact()
{
    std::cout << "Delete" << std::endl;
}

ContextualMenuPopup::~ContextualMenuPopup()
{
    delete ui;
}
