#include <iostream>
#include "contactwindow.h"
#include "conversationwindow.h"
#include "ui_contactwindow.h"
#include "addcontactwindow.h"
#include "contextualmenupopup.h"

ContactWindow::ContactWindow(NetworkObject *obj) :
    ui(new Ui::ContactWindow)
{
    ui->setupUi(this);
    ui->listContact->setContextMenuPolicy(Qt::CustomContextMenu);

}

ContactWindow::~ContactWindow()
{
    delete ui;
}

ConversationWindow *ContactWindow::createEmptyConversationWindow()
{
    return new ConversationWindow();
}

void ContactWindow::setLoginWindow(QWidget *login)
{
    lw = login;
}

void ContactWindow::addContact(QString name, QString ip)
{
    //if (db->addContact(name, ip) == true)
    //{
    ui->listContact->addItem(name + "\t" + ip);
    //Test ping
    //if (this->_network_object->Ping(name, ip) == true)
        ui->listContact->item(ui->listContact->count() -1)->setIcon(QIcon("./../Images/rond_vert.png"));
    //else
       // ui->listContact->item(0)->setIcon(QIcon("./../Images/rond_rouge.png"));
    //}
    //else
    //Erreur
 }

void ContactWindow::deleteContact()
{
    std::cout << "ERREUR DELETE" << std::endl;
    ui->listContact->takeItem(ui->listContact->row(ui->listContact->currentItem()));

}

void ContactWindow::on_actionDisconnect_triggered()
{
    this->close();
    lw->show();
}

void ContactWindow::on_actionExit_triggered()
{
    this->close();
}

void ContactWindow::on_actionAdd_Contact_triggered()
{
    AddContactWindow *acw = new AddContactWindow;
    acw->setContactWindow(this);
    acw->show();
}

void ContactWindow::on_actionSettings_triggered()
{

}

void ContactWindow::on_actionHistory_triggered()
{

}

void ContactWindow::on_listContact_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalpos = this->mapToGlobal(pos);
    ContextualMenuPopup cmp;
    cmp.InitMenu(globalpos, this);
}

NetworkObject *ContactWindow::getNetworkObject()
{
    return _network_object;
}

ConversationWindow *ContactWindow::getConvById(const QString &id)
{
    //TODO !!!!
    return NULL;
}

void ContactWindow::on_pushButton_clicked()
{
    AddContactWindow *acw = new AddContactWindow;
    acw->setContactWindow(this);
    acw->show();
}
