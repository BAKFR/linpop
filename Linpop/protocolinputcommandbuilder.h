#ifndef PROTOCOLINPUTCOMMANDBUILDER_H
#define PROTOCOLINPUTCOMMANDBUILDER_H

#include "corprotocolinputcommandbuilder.h"

class NetworkObject;
class NetworkClient;

class ProtocolInputCommandBuilder
{
protected:
    NetworkObject *networkObject;
    CORProtocolInputCommandBuilder *ptrCORProtocolInputCommandBuilder;
public:
    ProtocolInputCommandBuilder();
    void initialize(NetworkObject *no);
    ProtocolCommand *build(QByteArray query, NetworkClient *client);
    void addCOR(CORProtocolInputCommandBuilder *cor);
};

#endif // PROTOCOLINPUTCOMMANDBUILDER_H
