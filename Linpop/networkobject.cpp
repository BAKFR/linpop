#include "networkobject.h"
#include "protocolcommandtype.h"
#include "protocolcommandparamconv.h"
#include "contactwindow.h"
#include <iostream>

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

NetworkClient *NetworkObject::createAndConnectNewNetworkClient(QString ip, int port)
{
    NetworkClient *myClient = new NetworkClient;
return myClient;
}

void NetworkObject::shutdownServer()
{
    this->networkServer.close();
}

void NetworkObject::startNewConversation(QString ip, QString username)
{
    NetworkClient *nc = this->getNetworkClientByIP(ip);
    if (nc == NULL)
    {
        nc = createAndConnectNewNetworkClient(ip, this->networkServer.getPort());
    }
    ConversationWindow *ecw = ptrContactWindow->createEmptyConversationWindow();
    ProtocolCommand *command = this->protocolInterpretor.createOutputCommand(COMMAND_MESSAGE_INVITATION, nc);
    ProtocolCommandParamConv conversation(ecw->getIDConv());
    command->getProtocolCommandParameter().addParamCommandConv(conversation);
    this->protocolInterpretor.executeCommand(command);
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
    delete networkClient;
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
