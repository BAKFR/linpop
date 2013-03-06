#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QMainWindow>
#include <networkclient.h>

class ContactWindow;
class ProtocolCommand;
class UploadWindow;

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
    UploadWindow    *_upload_window;
public:
    QString getIDConv() const;
    QList<NetworkClient *> getListClient();
    NetworkClient *getClientByUsername(QString username);
    explicit ConversationWindow(ContactWindow *parent);
    void setIDConv(QString IDConv);
    void addChatContact(NetworkClient *client);
    void rmChatContact(NetworkClient *client);
    bool isNetworkClientInConversation(NetworkClient *client);
    NetworkClient *getClientByIP(QString ip);
    ~ConversationWindow();
    void rebuildContactList();

    ContactWindow *getContactWindow();
    UploadWindow *getUploadWindow();
    void setUploadWindow(UploadWindow *ptr);

    void    broadcast(ProtocolCommand *cmd);

    void    AddText(QString message);
    QString getText();

    int     getNbMembers() const;
    QList<NetworkClient *>  &getClients();
    
    void receiveWizz();
private:
    Ui::ConversationWindow *ui;

public slots:
    void    on_uploadButton_clicked();
    void    on_sendButton_clicked();
    void    on_wizzButton_clicked();

private slots:
    void on_AddContact_clicked();
    void onWizzTimeout();
};

#endif // CONVERSATIONWINDOW_H
