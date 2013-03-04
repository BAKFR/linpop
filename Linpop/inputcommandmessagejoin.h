#ifndef INPUTCOMMANDMESSAGEJOIN_H
#define INPUTCOMMANDMESSAGEJOIN_H

#include "protocolcommand.h"

class InputCommandMessageJoin : public ProtocolCommand
{
public:
    InputCommandMessageJoin();
    bool execute();
};

#endif // INPUTCOMMANDMESSAGEJOIN_H
