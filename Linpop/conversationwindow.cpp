#include "conversationwindow.h"
#include "ui_conversationwindow.h"
#include "uploadwindow.h"
#include "contactwindow.h"

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
}

QString ConversationWindow::getIDConv()
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

        UploadWindow *_upload_window = new UploadWindow(this, file_window->selectedFiles().at(0));
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
    ProtocolInterpretor &refProtocolInterpretor = _contact_window->getNetworkObject()->getProtocolInterpretor();

    ProtocolCommand *command = refProtocolInterpretor.createOutputCommand(COMMAND_MESSAGE_SEND, NULL);
    ProtocolCommandParameter p;
    p.addParamCommandConv(ProtocolCommandParamConv(this->IDConv));
    p.addParamCommandText(ProtocolCommandParamText(this->ui->lineEdit->text()));
    command->setProtocolCommandParameter(p);
    broadcast(command);
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
    ui->textEdit->setHtml(message + " \r\n" + ui->textEdit->toHtml());
}

QString    ConversationWindow::getText()
{
    return (ui->lineEdit->text());
}
