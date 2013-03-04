#ifndef PROTOCOLCOMMANDTYPE_H
#define PROTOCOLCOMMANDTYPE_H


enum ProtocolCommandType {
    COMMAND_MESSAGE_TRANSFERT_FILE,
    COMMAND_MESSAGE_ACCEPT_FILE,
    COMMAND_MESSAGE_DECONNEXION,
    COMMAND_MESSAGE_INVITATION,
    COMMAND_MESSAGE_PING,
    COMMAND_MESSAGE_PONG,
    COMMAND_MESSAGE_SEND,
    COMMAND_MESSAGE_JOIN
};

#endif // PROTOCOLCOMMANDTYPE_H
