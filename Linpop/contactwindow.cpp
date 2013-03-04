#include "contactwindow.h"
#include "conversationwindow.h"
#include "ui_contactwindow.h"

ContactWindow::ContactWindow(NetworkObject *obj) :
    ui(new Ui::ContactWindow),
    _network_object(obj)
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

NetworkObject *ContactWindow::getNetworkObject()
{
    return _network_object;
}

ConversationWindow *ContactWindow::getConvById(const QString &id)
{
    //TODO !!!!
    return NULL;
}
