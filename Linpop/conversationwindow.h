#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QMainWindow>

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
    UploadWindow    *_upload_window;
public:
    QString getIDConv();
    explicit ConversationWindow(ContactWindow *parent = 0);
    ~ConversationWindow();

    ContactWindow *getContactWindow();
    UploadWindow *getUploadWindow();
    void setUploadWindow(UploadWindow *ptr);

    void    broadcast(ProtocolCommand *cmd);

    void    AddText(QString message);
    QString getText();
    
private:
    Ui::ConversationWindow *ui;

public slots:
    void    on_uploadButton_clicked();
};

#endif // CONVERSATIONWINDOW_H
