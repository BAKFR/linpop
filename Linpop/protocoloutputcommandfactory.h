#ifndef PROTOCOLOUTPUTCOMMANDFACTORY_H
#define PROTOCOLOUTPUTCOMMANDFACTORY_H

class NetworkClient;
class NetworkObject;
class ProtocolCommand;
//enum ProtocolCommandType;
#include "protocolcommandtype.h"

class ProtocolOutputCommandFactory
{
protected:
    NetworkObject *networkObject;
public:
    ProtocolOutputCommandFactory();
    void initialize(NetworkObject *no);
    ProtocolCommand *build(ProtocolCommandType type, NetworkClient *ptrDestinationOutputNetworkClient);
};

#endif // PROTOCOLOUTPUTCOMMANDFACTORY_H
