#ifndef INPUTCOMMANDMESSAGESEND_H
#define INPUTCOMMANDMESSAGESEND_H

#include "protocolcommand.h"

class InputCommandMessageSend : public ProtocolCommand
{
public:
    InputCommandMessageSend();
    InputCommandMessageSend(const InputCommandMessageSend &ref);
    bool execute();
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGESEND_H
