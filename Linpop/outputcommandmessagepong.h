#ifndef OUPUTCOMMANDMESSAGEPONG_H
#define OUPUTCOMMANDMESSAGEPONG_H

#include "protocolcommand.h"

class OutputCommandMessagePong : public ProtocolCommand
{
public:
    OutputCommandMessagePong();
    OutputCommandMessagePong(const OutputCommandMessagePong& ref);
    virtual bool execute();
    virtual ProtocolCommand* clone();
};

#endif // OUPUTCOMMANDMESSAGEPONG_H
