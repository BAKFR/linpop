#include "networkclient.h"
#include "protocolcommand.h"
#include "networkobject.h"
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>

NetworkClient::NetworkClient()
{
    client = NULL;
    ptrNetworkdObject = NULL;
}

void NetworkClient::initialize(NetworkObject *object, QTcpSocket *client)
{
    this->client = client;
    ptrNetworkdObject = object;

    this->ip = client->peerAddress().toString();
    connect(this->client, SIGNAL(readyRead()), this, SLOT(onReceivedData()));
    connect(this->client, SIGNAL(bytesWritten(qint64 bytes)), this, SLOT(onSendData(qint64 bytes)));
    connect(this->client, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

void NetworkClient::onNetworkSocketNotifyCommandExecuted(ProtocolCommand *c)
{
    this->listProtocolCommand.removeAll(c);
}

void NetworkClient::onReceivedData()
{
    circularBuffer.addData(this->client->readAll());
    QString query = circularBuffer.tryToGetCompleteCommand();
    if (query != "")
    {
        ProtocolCommand *command = this->ptrNetworkdObject->getProtocolInterpretor().createInputCommand(query.toUtf8(), this);
        if (command != NULL)
        {
            this->ptrNetworkdObject->getProtocolInterpretor().executeCommand(command);
        }
    }
}

void NetworkClient::onSendData(qint64 bytes)
{
    (void)bytes;
}

void NetworkClient::onDisconnected()
{
    qDebug()<<"Un client vient de se deconnecter !";
    this->ptrNetworkdObject->getListNetworkClient().removeAll(this);
}

QString NetworkClient::getIP()
{
    return this->ip;
}

QString NetworkClient::getUsername()
{
    return this->username;
}

void NetworkClient::setIP(QString ip)
{
    this->ip = ip;
}

void NetworkClient::setUsername(QString username)
{
    this->username = username;
}

QTcpSocket *NetworkClient::getTcpSocket()
{
    return client;
}
