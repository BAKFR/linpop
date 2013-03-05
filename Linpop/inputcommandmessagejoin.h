#ifndef INPUTCOMMANDMESSAGEJOIN_H
#define INPUTCOMMANDMESSAGEJOIN_H

#include "protocolcommand.h"

class InputCommandMessageJoin : public ProtocolCommand
{
public:
    InputCommandMessageJoin();
    InputCommandMessageJoin(const InputCommandMessageJoin &ref);
    bool execute();
    virtual ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGEJOIN_H
