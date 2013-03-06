#ifndef NETWORKOBJECT_H
#define NETWORKOBJECT_H

#include <QList>
#include "protocolinterpretor.h"
#include "networkserver.h"

class ContactWindow;
class NetworkClient;

class NetworkObject
{
protected:
    QList<NetworkClient *> listNetworkClient;
    ProtocolInterpretor protocolInterpretor;
    NetworkServer networkServer;
    ContactWindow *ptrContactWindow;
public:
    NetworkObject(ContactWindow *ptrContactWindow = NULL);
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
    void rmNetworkClient(NetworkClient *networkClient);

    void setContactWindow(ContactWindow *win);

    ProtocolInterpretor &getProtocolInterpretor();
};

#endif // NETWORKOBJECT_H
