#ifndef FILETRANSFERTUPLOAD_H
#define FILETRANSFERTUPLOAD_H

#include <QFileInfo>
#include <QTcpSocket>

class NetworkObject;
class NetworkClient;
class ConversationWindow;

class FileTransfertUpload : public QObject
{
    Q_OBJECT

public:
    FileTransfertUpload(const QFileInfo &info, NetworkObject *interpretor, ConversationWindow *conv);
    ~FileTransfertUpload();

    void receiveAcceptFile(NetworkClient *client, int port);
    int getTotal() const;

public slots:
    void onSocketConnected();
    void onSocketError(QAbstractSocket::SocketError);
    void onSocketWritten();

signals:
    void error(const QString &msg);
    void complete(int, int, int);
    void progress(int, int, int);
    void clientError(const QString &msg);

private:
    QFileInfo   info;
    int         _total;
    int         _completed;
    int         _errors;

    QFile       *_file;
    void check_nbr();
};

#endif // FILETRANSFERTUPLOAD_H
