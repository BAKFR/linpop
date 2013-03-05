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
}

void ConversationWindow::on_uploadButton_clicked()
{
    QFileDialog *file_window = new QFileDialog(this, "Select a file to upload");
    file_window->setFileMode(QFileDialog::ExistingFile);
    if (file_window->exec() == 1) {
        //A file is choosen.

        //TODO: keep ptr on upload ?
        UploadWindow *up_win = new UploadWindow(this, file_window->selectedFiles().at(0));
        up_win->show();
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

void    ConversationWindow::AddText(QString message)
{
    ui->textEdit->setHtml(message + " \r\n" + ui->textEdit->toHtml());
}

QString    ConversationWindow::getText()
{
    return (ui->lineEdit->text());
}
