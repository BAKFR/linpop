#ifndef DOWNLOADWINDOW_H
#define DOWNLOADWINDOW_H

#include <QDialog>

namespace Ui {
class DownloadWindow;
}
class ConversationWindow;

class DownloadWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit DownloadWindow(ConversationWindow *parent = 0);
    ~DownloadWindow();
    
private:
    Ui::DownloadWindow *ui;
};

#endif // DOWNLOADWINDOW_H
