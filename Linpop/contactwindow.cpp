#include <iostream>
#include <QString>
#include <QTcpSocket>
#include <QMessageBox>
#include <QTime>
#include "contactwindow.h"
#include "conversationwindow.h"
#include "ui_contactwindow.h"
#include "addcontactwindow.h"
#include "contextualmenupopup.h"
#include "networkclient.h"
#include "networkobject.h"
#include "trayicon.h"

ContactWindow::ContactWindow(NetworkObject *obj) :
    ui(new Ui::ContactWindow), _network_object(obj)
{
    srand(QTime::currentTime().msec());
    ui->setupUi(this);
    ui->listContact->setContextMenuPolicy(Qt::CustomContextMenu);
    Trayicon(this);
}

ContactWindow::~ContactWindow()
{
    delete ui;
}

void    ContactWindow::initContactWindow(Database *_db, QString _login, QString _pwd)
{
    QList<Contact *> tmp;
    QString          name;
    QString          ip;
    int              iduser = this->db->getUser(_login, _pwd)->getIdUser();
    this->db = _db;
    this->login = _login;
    this->pwd = _pwd;
    tmp = this->db->getListContact(iduser);
    for (unsigned int i = 0; i < tmp.size(); i++)
    {
        name = tmp[i]->getContactName();
        ip = tmp[i]->getIp();
        ui->listContact->addItem(name + "\t" + ip);
        ui->listContact->item(ui->listContact->count() -1)->setIcon(QIcon(TestPing(ip)));
    }
}
QString ContactWindow::getPassword()
{
    return (this->pwd);
}
ConversationWindow *ContactWindow::createEmptyConversationWindow()
{
    ConversationWindow* cw = new ConversationWindow(this);
    this->listConversationWindow.append(cw);
    return cw;
}

void    ContactWindow::removeConv(ConversationWindow *w)
{
    this->listConversationWindow.removeOne(w);
}

void ContactWindow::setLoginWindow(QWidget *login)
{
    lw = login;
}

QString ContactWindow::getLogin()
{
    return (this->login);
}

void ContactWindow::setLogin(QString _login)
{
   this->login = _login;
}

QString ContactWindow::TestPing(QString ip)
{
    //Test ping
    QTcpSocket  *client = new QTcpSocket;
    NetworkClient *newclient = new NetworkClient;

    client->connectToHost(ip, 4242);
    if (client->waitForConnected(1000))
    {
        newclient->initialize(this->_network_object, client);
        return ("./../Images/rond_vert.png");
    }
    else
        return ("./../Images/rond_rouge.png");
}

void ContactWindow::addContact(QString name, QString ip)
{
    int         iduser = this->db->getUser(this->login, this->pwd)->getIdUser();
    if (this->db->getContact(iduser, name, ip) == NULL)
    {
        Contact     contact = Contact();
        contact.setContactName(name);
        contact.setIdUser(iduser);
        contact.setIp(ip);
        if (db->addContact(contact) != -1)
        {
            ui->listContact->addItem(name + "\t" + ip);
            ui->listContact->item(ui->listContact->count() -1)->setIcon(QIcon(TestPing(ip)));
        }
        else
            QMessageBox::warning(this, "Unable to add a contact", "Unable to create a contact.");
    }
    else
        QMessageBox::warning(this, "Unable to add a contact", "Unable to create a contact. This contact already exist");

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
    ui->listContact->item(ui->listContact->count() -1)->setIcon(QIcon("./../Images/rond_rouge.png"));
    ui->listContact->currentItem()->setIcon(QIcon(TestPing(ip)));
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
    int i = 0;
    while (i < this->listConversationWindow.size())
    {
        if (this->listConversationWindow.at(i)->getIDConv() == id)
        {
            return this->listConversationWindow.at(i);
        }
        i++;
    }
    return NULL;
}

int ContactWindow::hasConvByClient(NetworkClient *client)
{
    QList<ConversationWindow*>::Iterator it;
    for(it =  listConversationWindow.begin(); it != listConversationWindow.end(); ++it) {
        if ((*it)->isNetworkClientInConversation(client)) {
            return 1;
        }
    }
    return 0;
}

void ContactWindow::on_pushButton_clicked()
{
    AddContactWindow *acw = new AddContactWindow;
    acw->setContactWindow(this);
    acw->show();
}

//A rajouter dans le header...
QString ContactWindow::generateID()
{
    int value = rand();
    return QString::number(value);
}

//A rajouter dans le header et penser a ajouter le port dans NetworkServer aussi.
NetworkClient *ContactWindow::createAndConnectNetworkClientOnIP(QString ip)
{
    QTcpSocket  *client = new QTcpSocket;
    NetworkClient *newclient = new NetworkClient;

    client->connectToHost(ip, 5000);
    if (client->waitForConnected(1000))
    {
        newclient->initialize(this->_network_object, client);
        return newclient;
    }
    delete newclient;
    return NULL;
}


void ContactWindow::on_listContact_doubleClicked(QModelIndex idx)
{

    QString name = this->getName();
    QString ip = this->getIp();

    NetworkClient *client = this->createAndConnectNetworkClientOnIP(ip);
    if (client != NULL)
    {
        ProtocolCommand *command = this->getNetworkObject()->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_INVITATION, client);
        ProtocolCommandParameter p;

        QString idConv = generateID();
        p.addParamCommandConv(ProtocolCommandParamConv(idConv));
        p.addParamCommandUser(ProtocolCommandParamUser(this->getLogin(), "INSERT IP HERE"));
        command->setProtocolCommandParameter(p);
        if (this->getNetworkObject()->getProtocolInterpretor().executeCommand(command) == true)
        {
            ConversationWindow *cw = createEmptyConversationWindow();
            cw->show();
            cw->setIDConv(idConv);
            return;
        }
    }
    QMessageBox::warning(this, "Contact unreachable", "Unable to reach contact. Check the ip adress before trying connecting again.");
}

