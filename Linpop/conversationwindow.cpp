#include "conversationwindow.h"
#include "ui_conversationwindow.h"
#include "uploadwindow.h"
#include "contactwindow.h"

#include "protocolcommand.h"
#include "networkobject.h"

#include <QFileDialog>
#include <QDebug>

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

void    ConversationWindow::broadcast(ProtocolCommand *cmd)
{

    for (;false;)   //TODO: pour chaque NetworkClient !
    {
        ProtocolCommand *cmdCopy = cmd->clone();

        cmdCopy->setOutputNetworkClient(NULL);
        _contact_window->getNetworkObject()->getProtocolInterpretor().executeCommand(cmdCopy);
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
