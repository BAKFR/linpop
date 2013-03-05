#ifndef UPLOADWINDOW_H
#define UPLOADWINDOW_H

#include <QDialog>

#include "filetransfertupload.h"

namespace Ui {
class UploadWindow;
}

class ConversationWindow;
class NetworkClient;

class UploadWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit UploadWindow(ConversationWindow *parent, const QString &file);
    ~UploadWindow();

    void onAcceptFile(int port, NetworkClient *client);
    

public slots:
    void onUploadComplete(int nb_ok, int nb_error, int nb_total);
    void onUploadProgress(int nb_ok, int nb_error, int nb_total);
    void onUploadError(const QString &error);
    void onClientError(const QString &error);

    //TODO: debug code
    void on_pushButton_clicked() {
        onUploadComplete(1, 2, 3);
    }

    //Cancel upload (or just close window)
    void on_buttonBox_rejected();

private:
    ConversationWindow *_conv_win;
    Ui::UploadWindow *ui;
    FileTransfertUpload *ft_upload;
};

#endif // UPLOADWINDOW_H
