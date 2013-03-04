#ifndef INPUTCOMMANDMESSAGEPING_H
#define INPUTCOMMANDMESSAGEPING_H

#include "protocolcommand.h"

class InputCommandMessagePing : public ProtocolCommand
{
public:
    InputCommandMessagePing();
    InputCommandMessagePing(const InputCommandMessagePing &ref);
    bool execute();
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGEPING_H
