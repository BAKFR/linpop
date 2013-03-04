#ifndef NETWORKOBJECT_H
#define NETWORKOBJECT_H

#include <QList>
#include "protocolinterpretor.h"
#include "networkclient.h"
#include "networkserver.h"
#include "contactwindow.h"


class NetworkObject
{
protected:
    QList<NetworkClient *> listNetworkClient;
    ProtocolInterpretor protocolInterpretor;
    NetworkServer networkServer;
    ContactWindow *ptrContactWindow;
public:
    NetworkObject(ContactWindow *ptrContactWindow);
    bool initialize(int port);
    NetworkServer &getNetworkServer();
    QList<NetworkClient *>& getListNetworkClient();
    NetworkClient *createAndConnectNewNetworkClient(QString ip, int port);
    void shutdownServer();
    ContactWindow *getContactWindow();
    void startNewConversation(QString ip, QString username);
    NetworkClient *getNetworkClientByIP(QString ip);
    NetworkClient *getNetworkClientByUsername(QString username);
    void addNetworkClient(NetworkClient *networkClient);
};

#endif // NETWORKOBJECT_H
