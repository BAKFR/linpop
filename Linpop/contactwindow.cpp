#include "contactwindow.h"
#include "conversationwindow.h"
#include "ui_contactwindow.h"

ContactWindow::ContactWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ContactWindow)
{
    ui->setupUi(this);
}

ConversationWindow *ContactWindow::createEmptyConversationWindow()
{
    return new ConversationWindow();
}

ContactWindow::~ContactWindow()
{
    delete ui;
}
