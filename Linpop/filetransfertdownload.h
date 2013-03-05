#ifndef FILETRANSFERTDOWNLOAD_H
#define FILETRANSFERTDOWNLOAD_H

#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

class NetworkObject;
class NetworkClient;

class FileTransfertDownload : public QObject
{
    Q_OBJECT

public:
    FileTransfertDownload(NetworkObject *net_obj, const QString &conv_id, NetworkClient *target, const QString &file_path, int size);
    ~FileTransfertDownload();

    void stop();

    static void reject(NetworkObject *net_obj, const QString &conv_id, NetworkClient *target);

signals:
    void start();
    void error(const QString &msg);
    void progress(int current_size, int total_size);
    void complete();

private slots:
    void onSocketOpen();
    void onSocketError();
    void onSocketDisconnected();
    void onSocketReadyRead();

private:
    QTcpServer  *_server;
    QTcpSocket  *_socket;
    QFile       *_file;
    int         _current_size;
    int         _total_size;
};

#endif // FILETRANSFERTDOWNLOAD_H
