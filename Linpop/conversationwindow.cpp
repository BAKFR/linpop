#include "conversationwindow.h"
#include "ui_conversationwindow.h"
#include "uploadwindow.h"

#include <QFileDialog>
#include <QDebug>

ConversationWindow::ConversationWindow(QWidget *parent) :
    QMainWindow(parent),
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
