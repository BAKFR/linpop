#include "protocolinterpretor.h"


ProtocolInterpretor::ProtocolInterpretor()
{
}

void ProtocolInterpretor::initialize(NetworkObject *net_obj)
{
    protocolInputCommandBuilder.initialize(net_obj);
    protocolOutputCommandFactory.initialize(net_obj);
}

ProtocolCommand *ProtocolInterpretor::createInputCommand(QByteArray query, NetworkClient *networkClient)
{
    return this->protocolInputCommandBuilder.build(query, networkClient);
}

ProtocolCommand *ProtocolInterpretor::createOutputCommand(ProtocolCommandType type, NetworkClient *networkClient)
{
    return this->protocolOutputCommandFactory.build(type, networkClient);
}

ProtocolInputCommandBuilder &ProtocolInterpretor::getProtocolInputCommandBuilder()
{
    return protocolInputCommandBuilder;
}

bool ProtocolInterpretor::executeCommand(ProtocolCommand *command)
{
    bool result = false;

    if (command->getValidity() == true)
    {
        result = command->execute();
    }
    command->notifyNetworkClientCommandExecuted();
    delete command;
    return result;
}
