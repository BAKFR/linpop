#ifndef INPUTCOMMANDMESSAGEPONG_H
#define INPUTCOMMANDMESSAGEPONG_H

#include "protocolcommand.h"

class InputCommandMessagePong : public ProtocolCommand
{
public:
    InputCommandMessagePong();
    InputCommandMessagePong(const InputCommandMessagePong &ref);
    virtual bool execute();
    virtual ProtocolCommand* clone();
};

#endif // INPUTCOMMANDMESSAGEPONG_H
