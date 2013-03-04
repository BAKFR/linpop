#ifndef INPUTCOMMANDMESSAGEDECONNECTION_H
#define INPUTCOMMANDMESSAGEDECONNECTION_H

#include "protocolcommand.h"

class InputCommandMessageDeconnection : public ProtocolCommand
{
public:
    InputCommandMessageDeconnection();
    bool execute();
};

#endif // INPUTCOMMANDMESSAGEDECONNECTION_H
