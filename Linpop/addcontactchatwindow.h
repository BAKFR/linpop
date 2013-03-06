#ifndef ADDCONTACTCHATWINDOW_H
#define ADDCONTACTCHATWINDOW_H

#include <QDialog>
#include "conversationwindow.h"

namespace Ui {
class AddContactChatWindow;
}

class AddContactChatWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddContactChatWindow(ConversationWindow *, QWidget *parent = 0);
    ~AddContactChatWindow();
    
private slots:
    void on_bAddContact_clicked();

private:
    Ui::AddContactChatWindow *ui;
    ConversationWindow       *cw;
};

#endif // ADDCONTACTCHATWINDOW_H
