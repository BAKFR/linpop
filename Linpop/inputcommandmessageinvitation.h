#ifndef INPUTCOMMANDMESSAGEINVITATION_H
#define INPUTCOMMANDMESSAGEINVITATION_H

#include "protocolcommand.h"

class InputCommandMessageInvitation : public ProtocolCommand
{
private:
    void findAndAssociateTheUserNameOfTheInputClient(QList<ProtocolCommandParamUser> &list, NetworkClient *networkClient);
public:
    InputCommandMessageInvitation();
    InputCommandMessageInvitation(const InputCommandMessageInvitation &ref);
    bool execute();
    void broadcastCommandJoin(QList<ProtocolCommandParamUser> &list, ProtocolCommand* command_join);
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGEINVITATION_H
