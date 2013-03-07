#include "conversationwindow.h"
#include "ui_conversationwindow.h"
#include "uploadwindow.h"
#include "contactwindow.h"
#include "addcontactchatwindow.h"
#include "networkclient.h"

#include "protocolcommand.h"
#include "networkobject.h"

#include <QFileDialog>
#include <QListWidget>
#include <QDebug>
#include <QLineEdit>
#include <QTimer>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QUrl>
#include <QMimeData>


ConversationWindow::ConversationWindow(ContactWindow *parent) :
    QMainWindow(parent), _contact_window(parent),
    _upload_window(NULL),
    ui(new Ui::ConversationWindow)
{
    setAttribute(Qt::WA_DeleteOnClose);
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

    ProtocolInterpretor &refProtocolInterpretor = _contact_window->getNetworkObject()->getProtocolInterpretor();

    ProtocolCommand *command = refProtocolInterpretor.createOutputCommand(COMMAND_MESSAGE_DECONNEXION, NULL);
    ProtocolCommandParameter p;
    p.addParamCommandConv(ProtocolCommandParamConv(this->IDConv));
    command->setProtocolCommandParameter(p);
    broadcast(command);

    _contact_window->removeConv(this);
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
    ui->lineEdit->setEnabled(true);
    ui->sendButton->setEnabled(true);
    ui->uploadButton->setEnabled(true);
    ui->wizzButton->setEnabled(true);
}

void ConversationWindow::rmChatContact(NetworkClient *client)
{
    listClient.removeOne(client);
    rebuildContactList();
    if (listClient.count() == 0) {
        ui->lineEdit->setEnabled(false);
        ui->sendButton->setEnabled(false);
        ui->uploadButton->setEnabled(false);
        ui->wizzButton->setEnabled(false);
    }
}



void ConversationWindow::rebuildContactList() {
    QList<NetworkClient*>::Iterator it;

    ui->contactList->clear();
    for (it = listClient.begin(); it != listClient.end(); ++it) {
        ui->contactList->addItem((*it)->getUsername() + " " + (*it)->getIP());
    }
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
        this->AddText(_contact_window->getLogin() +" dit :" + ui->lineEdit->text());
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
    QList<QPair<QString, QString> > smileys;
    smileys.append(QPair<QString, QString>("8$", "1.png"));
    smileys.append(QPair<QString, QString>(":angel:", "angel.png"));
    smileys.append(QPair<QString, QString>(":devil:", "devil.png"));
    smileys.append(QPair<QString, QString>(":down:", "up.png"));
    smileys.append(QPair<QString, QString>(":up:", "down.png"));
    smileys.append(QPair<QString, QString>(":love:", "love.png"));
    smileys.append(QPair<QString, QString>(":D", "2.png"));
    smileys.append(QPair<QString, QString>("oo", "3.png"));
    smileys.append(QPair<QString, QString>("oO", "4.png"));
    smileys.append(QPair<QString, QString>(":O", "5.png"));
    smileys.append(QPair<QString, QString>("><", "6.png"));
    smileys.append(QPair<QString, QString>("=]", "7.png"));
    smileys.append(QPair<QString, QString>("^^", "8.png"));
    smileys.append(QPair<QString, QString>("-_-", "9.png"));
    smileys.append(QPair<QString, QString>(":stop:", "stop.png"));
    smileys.append(QPair<QString, QString>(":)", "10.png"));
    smileys.append(QPair<QString, QString>(":(", "11.png"));
    smileys.append(QPair<QString, QString>(":\\", "12.png"));
    smileys.append(QPair<QString, QString>(":p", "13.png"));
    smileys.append(QPair<QString, QString>(":'(", "14.png"));

    QList<QPair<QString, QString> >::Iterator it;

    for (it = smileys.begin(); it != smileys.end(); ++it)
        message.replace(it->first, QString("<img src=\"../Images/smiley/") + it->second + "\" />");


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

void ConversationWindow::on_wizzButton_clicked()
{
    ProtocolInterpretor &refProtocolInterpretor = _contact_window->getNetworkObject()->getProtocolInterpretor();
    ProtocolCommand *command = refProtocolInterpretor.createOutputCommand(COMMAND_MESSAGE_WIZZ, NULL);
    ProtocolCommandParameter p;

    p.addParamCommandConv(ProtocolCommandParamConv(this->IDConv));
    command->setProtocolCommandParameter(p);
    broadcast(command);
}

void ConversationWindow::receiveWizz()
{
    activateWindow();
    raise();
    QTimer *timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(onWizzTimeout()));
    timer->start();
}

void    ConversationWindow::onWizzTimeout()
{
    static int i = 0;

    if (i >= 40) {
        dynamic_cast<QTimer*>(sender())->deleteLater();
        i = 0;
    }

    i++;
    QPoint p = pos();
    p.rx() += ((i / 10) % 2) == 0 ? -1 : 1;
    move(p);
}


void ConversationWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (!_upload_window)
        event->acceptProposedAction();
}

void ConversationWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void ConversationWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (!_upload_window)
        event->acceptProposedAction();
}

void ConversationWindow::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();

    if (_upload_window)
        return;

    if (mimeData->hasUrls() && mimeData->urls().count() == 1
            && mimeData->urls().at(0).isLocalFile())
    {
        event->acceptProposedAction();

        _upload_window = new UploadWindow(this, mimeData->urls().at(0).toLocalFile());
        _upload_window->show();
    }
}
/*
#include "audioinput.h"
#include "audiooutput.h"
*/
void ConversationWindow::on_audioButton_clicked()
{/*
    new AudioOutput(this);
    new AudioInput(this, "127.0.0.1", 5001);
*/
}
