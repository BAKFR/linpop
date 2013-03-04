#ifndef INPUTCOMMANDMESSAGEPING_H
#define INPUTCOMMANDMESSAGEPING_H

#include "protocolcommand.h"

class InputCommandMessagePing : public ProtocolCommand
{
public:
    InputCommandMessagePing();
    bool execute();
};

#endif // INPUTCOMMANDMESSAGEPING_H
