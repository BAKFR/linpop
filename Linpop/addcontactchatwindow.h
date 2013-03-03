#ifndef ADDCONTACTCHATWINDOW_H
#define ADDCONTACTCHATWINDOW_H

#include <QDialog>

namespace Ui {
class AddContactChatWindow;
}

class AddContactChatWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddContactChatWindow(QWidget *parent = 0);
    ~AddContactChatWindow();
    
private:
    Ui::AddContactChatWindow *ui;
};

#endif // ADDCONTACTCHATWINDOW_H
