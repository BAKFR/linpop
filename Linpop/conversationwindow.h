#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QMainWindow>
#include <networkclient.h>

class ContactWindow;
class ProtocolCommand;

namespace Ui {
class ConversationWindow;
}

class ConversationWindow : public QMainWindow
{
    Q_OBJECT
protected:
    QString         IDConv;
    ContactWindow   *_contact_window;
    QList<NetworkClient *> listClient;
public:
    QString getIDConv();
    NetworkClient *getClientByUsername(QString username);
    explicit ConversationWindow(ContactWindow *parent = 0);
    void setIDConv(QString IDConv);
    void addChatContact(NetworkClient *client);
    bool isNetworkClientInConversation(NetworkClient *client);
    NetworkClient *getClientByIP(QString ip);
    ~ConversationWindow();

    ContactWindow *getContactWindow();

    void    broadcast(ProtocolCommand *cmd);
    
private:
    Ui::ConversationWindow *ui;

public slots:
    void    on_uploadButton_clicked();
    void    on_sendButton_clicked();
};

#endif // CONVERSATIONWINDOW_H
