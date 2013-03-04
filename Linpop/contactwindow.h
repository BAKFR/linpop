#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include "conversationwindow.h"
#include <QMainWindow>

namespace Ui {
class ContactWindow;
}

class ContactWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ContactWindow(QWidget *parent = 0);
    ConversationWindow *createEmptyConversationWindow();
    ~ContactWindow();

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
    //DatabaseObject  *db;
};

#endif // CONTACTWINDOW_H
