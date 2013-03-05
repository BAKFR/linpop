#ifndef OUPUTCOMMANDMESSAGEPING_H
#define OUPUTCOMMANDMESSAGEPING_H

#include "protocolcommand.h"

class OutputCommandMessagePing : public ProtocolCommand
{
public:
    OutputCommandMessagePing();
    OutputCommandMessagePing(const OutputCommandMessagePing &ref);
    virtual bool execute();
    virtual ProtocolCommand *clone();
};

#endif // OUPUTCOMMANDMESSAGEPING_H
