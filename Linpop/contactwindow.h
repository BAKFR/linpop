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
    
private:
    Ui::ContactWindow *ui;
};

#endif // CONTACTWINDOW_H
