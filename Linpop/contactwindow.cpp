#include <iostream>
#include "contactwindow.h"
#include "conversationwindow.h"
#include "ui_contactwindow.h"
#include "addcontactwindow.h"
#include "contextualmenupopup.h"

ContactWindow::ContactWindow(NetworkObject *obj) :
    ui(new Ui::ContactWindow), _network_object(obj)
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

QString ContactWindow::TestPing(QString user_name, QString ip)
{
    //Test ping
    //if (this->_network_object->Ping(name, ip) == true)
        return ("./../Images/rond_vert.png");
    //else
        //return ("./../Images/rond_rouge.png");

}

void ContactWindow::addContact(QString name, QString ip)
{
    //if (db->addContact(name, ip) == true)
    //{
    ui->listContact->addItem(name + "\t" + ip);

    ui->listContact->item(ui->listContact->count() -1)->setIcon(QIcon(TestPing(name, ip)));
    //}
    //else
    //Erreur
 }

void ContactWindow::deleteContact()
{
    //db->deleteContact(db->getContact(getName() , getIp()));
    ui->listContact->takeItem(ui->listContact->row(ui->listContact->currentItem()));
}

void ContactWindow::setContact(QString user_name, QString ip)
{
   // db->setContact(db.getContact(ui->listContact->currentItem()->text()), user_name, ip);
    ui->listContact->currentItem()->setText(user_name + "\t" + ip);
    ui->listContact->currentItem()->setIcon(QIcon(TestPing(user_name, ip)));
}

QString ContactWindow::getName(QString text)
{
    QString name;
    std::string tmp;
    std::string buf;

    if (text == "")
        text = ui->listContact->currentItem()->text();
    tmp = text.toStdString();
    for (unsigned int i = 0; (tmp[i] != '\t' || tmp[i] != ' ') && i < tmp.size(); i++)
        buf += tmp[i];
    name =  QString(buf.c_str());
    return (name);
}

QString ContactWindow::getIp(QString text)
{
    unsigned int i = 0;
    QString ip;
    std::string tmp;
    std::string buf;

    if (text == "")
        text = ui->listContact->currentItem()->text();
    tmp = text.toStdString();
    for (i = 0; tmp[i] != '\t' && tmp[i] != ' ' && i < tmp.size(); i++);
    for (i = i + 1; i < tmp.size(); i++)
        buf += tmp[i];
    ip =  QString(buf.c_str());
    return (ip);
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
