#ifndef INPUTCOMMANDMESSAGEPONG_H
#define INPUTCOMMANDMESSAGEPONG_H

#include "protocolcommand.h"

class InputCommandMessagePong : public ProtocolCommand
{
public:
    InputCommandMessagePong();
    bool execute();
};

#endif // INPUTCOMMANDMESSAGEPONG_H
