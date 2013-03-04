#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QList>
#include "networkclient.h"
#include "circularbuffer.h"
//#include "protocolcommand.h"

class ProtocolCommand;
class NetworkObject;

class NetworkClient : QObject
{
    Q_OBJECT
   protected:
    CircularBuffer circularBuffer;
    QTcpSocket *client;
    NetworkObject *ptrNetworkdObject;
    QString ip;
    QString username;
    QList<ProtocolCommand *> listProtocolCommand;
public:
    NetworkClient();
    void onNetworkSocketNotifyCommandExecuted(ProtocolCommand *c);
    void initialize(NetworkObject *object, QTcpSocket *client);
public slots:
    QString getIP();
    QString getUsername();
    void setIP(QString ip);
    void setUsername(QString username);
    void onReceivedData();
    void onSendData(qint64 bytes);
    void onDisconnected();

    QTcpSocket *getTcpSocket();
};

#endif // NETWORKCLIENT_H
