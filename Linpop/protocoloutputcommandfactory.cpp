#include "protocoloutputcommandfactory.h"
#include "ProtocolCommandType.h"
#include "networkobject.h"
#include "outputcommandmessagetransfertfile.h"
#include "outputcommandmessageacceptfile.h"
#include "outputcommandmessagedeconnection.h"
#include "outputcommandmessageinvitation.h"
#include "outputcommandmessageping.h"
#include "outputcommandmessagepong.h"
#include "outputcommandmessagesend.h"
#include "outputcommandmessagejoin.h"

ProtocolOutputCommandFactory::ProtocolOutputCommandFactory()
{
    this->networkObject = NULL;
}

void ProtocolOutputCommandFactory::initialize(NetworkObject *no)
{
    this->networkObject = no;
}

ProtocolCommand *ProtocolOutputCommandFactory::build(ProtocolCommandType type, NetworkClient *ptrDestinationOutputNetworkClient)
{
    ProtocolCommand *command = NULL;
    switch (type)
    {
    case COMMAND_MESSAGE_TRANSFERT_FILE:
        command = new OutputCommandMessageTransfertFile();
        break;
    case COMMAND_MESSAGE_ACCEPT_FILE:
        command = new OutputCommandMessageAcceptFile();
        break;
    case COMMAND_MESSAGE_DECONNEXION:
        command = new OutputCommandMessageDeconnection();
        break;
    case COMMAND_MESSAGE_INVITATION:
        command = new OutputCommandMessageInvitation();
        break;
    case COMMAND_MESSAGE_PING:
        command = new OutputCommandMessagePing();
        break;
    case COMMAND_MESSAGE_PONG:
        command = new OutputCommandMessagePong();
        break;
    case COMMAND_MESSAGE_SEND:
        command = new OutputCommandMessageSend();
        break;
    case COMMAND_MESSAGE_JOIN:
        command = new OutputCommandMessageJoin();
        break;
    }
    if (command != NULL)
    {
        command->setContactWindow(this->networkObject->getContactWindow());
    }
    return command;
}
