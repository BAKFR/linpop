#include "downloadwindow.h"
#include "ui_downloadwindow.h"

#include "conversationwindow.h"

DownloadWindow::DownloadWindow(ConversationWindow *parent) :
    QDialog(parent),
    ui(new Ui::DownloadWindow)
{
    ui->setupUi(this);
}

DownloadWindow::~DownloadWindow()
{
    delete ui;
}
