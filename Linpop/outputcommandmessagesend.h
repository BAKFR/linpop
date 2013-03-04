#ifndef OUTPUTCOMMANDMESSAGESEND_H
#define OUTPUTCOMMANDMESSAGESEND_H

#include "protocolcommand.h"

class OutputCommandMessageSend : public ProtocolCommand
{
public:
    OutputCommandMessageSend();
    virtual bool execute();
};

#endif // OUTPUTCOMMANDMESSAGESEND_H
