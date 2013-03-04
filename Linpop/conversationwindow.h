#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class ConversationWindow;
}

class ConversationWindow : public QMainWindow
{
    Q_OBJECT
protected:
    QString IDConv;
public:
    QString getIDConv();
    explicit ConversationWindow(QWidget *parent = 0);
    ~ConversationWindow();
    
private:
    Ui::ConversationWindow *ui;

public slots:
    void    on_uploadButton_clicked();
};

#endif // CONVERSATIONWINDOW_H
