#ifndef PROTOCOLINTERPRETOR_H
#define PROTOCOLINTERPRETOR_H

//#include "networkobject.h"
//#include "networkclient.h"
//#include "ProtocolCommandType.h"
#include "protocoloutputcommandfactory.h"
#include "protocolinputcommandbuilder.h"
#include <QByteArray>


class ProtocolCommand;
enum ProtocolCommandType;
class NetworkClient;
class NetworkObject;

class ProtocolInterpretor
{
protected:
    ProtocolOutputCommandFactory protocolOutputCommandFactory;
    ProtocolInputCommandBuilder protocolInputCommandBuilder;
public:
    ProtocolInterpretor();
    void initialize(NetworkObject *net_obj);
    ProtocolCommand *createInputCommand(QByteArray query, NetworkClient *networkClient);
    ProtocolCommand *createOutputCommand(ProtocolCommandType type, NetworkClient *networkClient);
    bool executeCommand(ProtocolCommand *command);
};

#endif // PROTOCOLINTERPRETOR_H
