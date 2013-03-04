#ifndef INPUTCOMMANDMESSAGEDECONNECTION_H
#define INPUTCOMMANDMESSAGEDECONNECTION_H

#include "protocolcommand.h"

class InputCommandMessageDeconnection : public ProtocolCommand
{
public:
    InputCommandMessageDeconnection();
    InputCommandMessageDeconnection(const InputCommandMessageDeconnection &ref);
    bool execute();
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGEDECONNECTION_H
