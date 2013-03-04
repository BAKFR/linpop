#ifndef OUPUTCOMMANDMESSAGEPONG_H
#define OUPUTCOMMANDMESSAGEPONG_H

#include "protocolcommand.h"

class OutputCommandMessagePong : public ProtocolCommand
{
public:
    OutputCommandMessagePong();
    virtual bool execute();
};

#endif // OUPUTCOMMANDMESSAGEPONG_H
