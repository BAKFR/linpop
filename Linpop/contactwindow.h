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

    NetworkObject* getNetworkObject();
    ConversationWindow *getConvById(const QString &id);
    void setLoginWindow(QWidget *);
    void addContact(QString name, QString ip);

private slots:

    void on_actionDisconnect_triggered();

    void on_actionExit_triggered();

    void on_actionAdd_Contact_triggered();

    void on_actionSettings_triggered();

    void on_actionHistory_triggered();

    void on_listContact_customContextMenuRequested(const QPoint &pos);
    
private:
    Ui::ContactWindow *ui;
    QWidget           *lw;
    NetworkObject       *_network_object;
    //DatabaseObject  *db;
};

#endif // CONTACTWINDOW_H
