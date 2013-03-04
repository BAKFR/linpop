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
    //db->addContact(name, ip);
    ui->listContact->addItem(name + "\n" + ip);
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
