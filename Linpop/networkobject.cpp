#include "networkobject.h"
#include "protocolcommandtype.h"
#include "protocolcommandparamconv.h"
#include "contactwindow.h"
#include "networkclient.h"
#include "conversationwindow.h"

//#include <iostream>

NetworkObject::NetworkObject(ContactWindow *ptrContactWindow)
    : protocolInterpretor()
{
    this->ptrContactWindow = ptrContactWindow;
}

bool NetworkObject::initialize(int port)
{
    protocolInterpretor.initialize(this);
    return networkServer.initialize(port, this);
}

ContactWindow *NetworkObject::getContactWindow()
{
    return this->ptrContactWindow;
}

QList<NetworkClient *>& NetworkObject::getListNetworkClient()
{
    return this->listNetworkClient;
}

NetworkServer &NetworkObject::getNetworkServer()
{
    return this->networkServer;
}


NetworkClient *NetworkObject::getNetworkClientByIP(QString ip)
{
    int i = 0;
    int max = this->listNetworkClient.size();
    while (i < max)
    {
        if (this->listNetworkClient.at(i)->getIP() == ip)
        {
            return this->listNetworkClient.at(i);
        }
        i++;
    }
    return NULL;
}

NetworkClient *NetworkObject::getNetworkClientByUsername(QString username)
{
    int i = 0;
    int max = this->listNetworkClient.size();
    while (i < max)
    {
        if (this->listNetworkClient.at(i)->getUsername() == username)
        {
            return this->listNetworkClient.at(i);
        }
        i++;
    }
    return NULL;
}

void NetworkObject::addNetworkClient(NetworkClient *networkClient)
{
    this->listNetworkClient.append(networkClient);
}

void NetworkObject::rmNetworkClient(NetworkClient *networkClient)
{
    this->listNetworkClient.removeOne(networkClient);
    networkClient->deleteLater();
}

void NetworkObject::setContactWindow(ContactWindow *win)
{
    ptrContactWindow = win;
    protocolInterpretor.getProtocolInputCommandBuilder().initialize(this);
}

ProtocolInterpretor &NetworkObject::getProtocolInterpretor()
{
    return protocolInterpretor;
}
