#include "networkserver.h"
#include "networkclient.h"
#include "networkobject.h"
#include <QDebug>
#include <QTcpSocket>



NetworkServer::NetworkServer(QObject *parent) :
    QTcpServer(parent)
{

}

int NetworkServer::getPort()
{
    return this->port;
}

bool NetworkServer::initialize(int port, NetworkObject *networkObject)
{
    ptrNetworkObject = networkObject;
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    return this->listen(QHostAddress::Any, port);
}

void NetworkServer::onNewConnection()
{
    this->createNewClient();
}

NetworkClient* NetworkServer::createNewClient()
{
    qDebug()<<"A new connection has been catched...";
    QTcpSocket *client = this->nextPendingConnection();
    client->write("You are connnected.\r\n");
    NetworkClient *networkClient = new NetworkClient();
    networkClient->initialize(ptrNetworkObject, client);
    ptrNetworkObject->getListNetworkClient().append(networkClient);
    return networkClient;
}

