#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include "conversationwindow.h"
#include <QMainWindow>

namespace Ui {
class ContactWindow;
}

class NetworkObject;



class ContactWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    ContactWindow(NetworkObject *obj);
    ConversationWindow *createEmptyConversationWindow();
    ~ContactWindow();

    NetworkObject *getNetworkObject();
    ConversationWindow *getConvById(const QString &id);

private:
    Ui::ContactWindow   *ui;
    NetworkObject       *_network_object;
};

#endif // CONTACTWINDOW_H
