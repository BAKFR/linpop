#include "conversationwindow.h"
#include "ui_conversationwindow.h"

ConversationWindow::ConversationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConversationWindow)
{
    ui->setupUi(this);
}

ConversationWindow::~ConversationWindow()
{
    delete ui;
}
