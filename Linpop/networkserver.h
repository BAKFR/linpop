#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <QTcpServer>
#include "networkclient.h"

class NetworkObject;


class NetworkServer : public QTcpServer
{
    Q_OBJECT
protected:
    int port;
    NetworkObject *ptrNetworkObject;
private:
    NetworkClient *createNewClient();
public:
    int getPort();
    explicit NetworkServer(QObject *parent = 0);
    bool initialize(int port, NetworkObject *networkObject);
public slots:
    void onNewConnection();
};

#endif // NETWORKSERVER_H
