#include "conversationwindow.h"
#include "ui_conversationwindow.h"
#include "uploadwindow.h"
#include "contactwindow.h"
#include "addcontactchatwindow.h"

#include "protocolcommand.h"
#include "networkobject.h"

#include <QFileDialog>
#include <QListWidget>
#include <QDebug>
#include <QLineEdit>

ConversationWindow::ConversationWindow(ContactWindow *parent) :
    QMainWindow(parent), _contact_window(parent),
    _upload_window(NULL),
    ui(new Ui::ConversationWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_sendButton_clicked()));
}

QList<NetworkClient *> ConversationWindow::getListClient()
{
    return this->listClient;
}

QString ConversationWindow::getIDConv() const
{
    return this->IDConv;
}

ConversationWindow::~ConversationWindow()
{
    delete ui;
    delete _upload_window;
}

void ConversationWindow::on_uploadButton_clicked()
{
    if (_upload_window)
        return;

    QFileDialog *file_window = new QFileDialog(this, "Select a file to upload");
    file_window->setFileMode(QFileDialog::ExistingFile);
    if (file_window->exec() == 1) {
        //A file is choosen.

        _upload_window = new UploadWindow(this, file_window->selectedFiles().at(0));
        _upload_window->show();
    }
    delete file_window;
}


ContactWindow *ConversationWindow::getContactWindow()
{
    return _contact_window;
}

void ConversationWindow::addChatContact(NetworkClient *client)
{
    listClient.append(client);
    this->ui->contactList->addItem(client->getUsername() + " " + client->getIP());
}

bool ConversationWindow::isNetworkClientInConversation(NetworkClient *client)
{
    int i = 0;
    while (i < this->listClient.size())
    {
        if (listClient.at(i) == client)
            return true;
        i++;
    }
    return false;
}

NetworkClient *ConversationWindow::getClientByIP(QString ip)
{
    int i = 0;
    while (i < this->listClient.size())
    {
        if (listClient.at(i)->getIP() == ip)
            return listClient.at(i);
        i++;
    }
    return NULL;
}

void    ConversationWindow::on_sendButton_clicked()
{
    if (ui->lineEdit->text() != "")
    {
        this->AddText(this->getContactWindow()->getLogin() +" dit :" + ui->lineEdit->text());
        ProtocolInterpretor &refProtocolInterpretor = _contact_window->getNetworkObject()->getProtocolInterpretor();

        ProtocolCommand *command = refProtocolInterpretor.createOutputCommand(COMMAND_MESSAGE_SEND, NULL);
        ProtocolCommandParameter p;
        p.addParamCommandConv(ProtocolCommandParamConv(this->IDConv));
        p.addParamCommandText(ProtocolCommandParamText(this->ui->lineEdit->text()));
        command->setProtocolCommandParameter(p);
        broadcast(command);
        this->ui->lineEdit->setText("");
    }
}

NetworkClient *ConversationWindow::getClientByUsername(QString username)
{
    int i = 0;
    while (i < this->listClient.size())
    {
        if (listClient.at(i)->getUsername() == username)
            return listClient.at(i);
        i++;
    }
    return NULL;
}

void ConversationWindow::setIDConv(QString IDConv)
{
   this->IDConv = IDConv;
}

void    ConversationWindow::broadcast(ProtocolCommand *cmd)
{
    int i = 0;
    while (i < this->listClient.size())
    {
        ProtocolCommand *cmdCopy = cmd->clone();

        cmdCopy->setOutputNetworkClient(this->listClient.at(i));
        _contact_window->getNetworkObject()->getProtocolInterpretor().executeCommand(cmdCopy);
        i++;
    }
    delete cmd;
}

UploadWindow    *ConversationWindow::getUploadWindow()
{
    return _upload_window;
}

void ConversationWindow::setUploadWindow(UploadWindow *ptr)
{
    _upload_window = ptr;
}

void    ConversationWindow::AddText(QString message)
{
    if (ui->textEdit->toHtml() != "")
        ui->textEdit->setHtml(ui->textEdit->toHtml() + "\r\n" + message );
    else
       ui->textEdit->setHtml(message);
}

QString    ConversationWindow::getText()
{
    return (ui->lineEdit->text());
}

int     ConversationWindow::getNbMembers() const
{
    return listClient.size();
}

QList<NetworkClient *>  &ConversationWindow::getClients()
{
    return listClient;
}

void ConversationWindow::on_AddContact_clicked()
{
    AddContactChatWindow    *accw = new AddContactChatWindow(this);

    accw->show();
}
