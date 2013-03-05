#ifndef OUTPUTCOMMANDMESSAGESEND_H
#define OUTPUTCOMMANDMESSAGESEND_H

#include "protocolcommand.h"

class OutputCommandMessageSend : public ProtocolCommand
{
public:
    OutputCommandMessageSend();
    OutputCommandMessageSend(const OutputCommandMessageSend &ref);
    virtual bool execute();
    ProtocolCommand *clone();
};

#endif // OUTPUTCOMMANDMESSAGESEND_H
