#ifndef OUPUTCOMMANDMESSAGEPING_H
#define OUPUTCOMMANDMESSAGEPING_H

#include "protocolcommand.h"

class OutputCommandMessagePing : public ProtocolCommand
{
public:
    OutputCommandMessagePing();
    virtual bool execute();
};

#endif // OUPUTCOMMANDMESSAGEPING_H
