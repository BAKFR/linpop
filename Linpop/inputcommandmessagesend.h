#ifndef INPUTCOMMANDMESSAGESEND_H
#define INPUTCOMMANDMESSAGESEND_H

#include "protocolcommand.h"

class InputCommandMessageSend : public ProtocolCommand
{
public:
    InputCommandMessageSend();
    bool execute();
};

#endif // INPUTCOMMANDMESSAGESEND_H
