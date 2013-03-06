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
    FileTransfertDownload(NetworkObject *net_obj, const QString &conv_id, NetworkClient *target, const QString &file_path, qulonglong size);
    ~FileTransfertDownload();

    void stop();

    static void reject(NetworkObject *net_obj, const QString &conv_id, NetworkClient *target);

signals:
    void start();
    void error(const QString &msg);
    void progress(qulonglong current_size, qulonglong total_size);
    void complete();

private slots:
    void onSocketOpen();
    void onSocketError(QAbstractSocket::SocketError err);
    void onSocketDisconnected();
    void onSocketReadyRead();

private:
    QTcpServer  *_server;
    QTcpSocket  *_socket;
    QFile       *_file;
    qulonglong  _current_size;
    qulonglong  _total_size;
};

#endif // FILETRANSFERTDOWNLOAD_H
