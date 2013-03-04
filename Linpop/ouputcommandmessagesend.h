#ifndef OUPUTCOMMANDMESSAGESEND_H
#define OUPUTCOMMANDMESSAGESEND_H

#include "protocolcommand.h"

class OutputCommandMessageSend : public ProtocolCommand
{
public:
    OutputCommandMessageSend();
    OutputCommandMessageSend(const OutputCommandMessageSend& ref);
    virtual bool execute();
    virtual ProtocolCommand *clone();
};

#endif // OUPUTCOMMANDMESSAGESEND_H
