#ifndef DOWNLOADWINDOW_H
#define DOWNLOADWINDOW_H

#include <QDialog>

namespace Ui {
class DownloadWindow;
}

class ConversationWindow;
class NetworkObject;
class NetworkClient;
class FileTransfertDownload;

class DownloadWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit DownloadWindow(ConversationWindow *parent, NetworkObject *net_obj, NetworkClient *target, const QString &filename, qulonglong size);
    ~DownloadWindow();
    
public slots:
    void onDownloadStart();
    void onDownloadError(const QString &msg);
    void onDownloadProgress(qulonglong current_size, qulonglong total_size);
    void onDownloadComplete();

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DownloadWindow      *ui;
    FileTransfertDownload   *ft_download;
    QString                 _conv_id;
    NetworkObject           *_net_obj;
    NetworkClient           *_target;
    int                     _size;
};

#endif // DOWNLOADWINDOW_H
