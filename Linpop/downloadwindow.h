#ifndef DOWNLOADWINDOW_H
#define DOWNLOADWINDOW_H

#include <QDialog>

namespace Ui {
class DownloadWindow;
}

class ConversationWindow;
class NetworkObject;
class FileTransfertDownload;

class DownloadWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit DownloadWindow(ConversationWindow *parent, NetworkObject *net_obj, const QString &filename, int size);
    ~DownloadWindow();
    
public slots:
    void onDownloadStart();
    void onDownloadError(const QString &msg);
    void onDownloadProgress(int current_size, int total_size);
    void onDownloadComplete();

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DownloadWindow      *ui;
    FileTransfertDownload   *ft_download;
};

#endif // DOWNLOADWINDOW_H
