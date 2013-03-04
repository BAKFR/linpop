#include "protocolinterpretor.h"

ProtocolInterpretor::ProtocolInterpretor()
{
}

ProtocolCommand *ProtocolInterpretor::createInputCommand(QByteArray query, NetworkClient *networkClient)
{
    return this->protocolInputCommandBuilder.build(query, networkClient);
}

ProtocolCommand *ProtocolInterpretor::createOutputCommand(ProtocolCommandType type, NetworkClient *networkClient)
{
    return this->protocolOutputCommandFactory.build(type, networkClient);
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
