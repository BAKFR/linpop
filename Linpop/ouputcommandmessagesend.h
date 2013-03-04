#ifndef OUPUTCOMMANDMESSAGESEND_H
#define OUPUTCOMMANDMESSAGESEND_H

#include "protocolcommand.h"

class OutputCommandMessageSend : public ProtocolCommand
{
public:
    OutputCommandMessageSend();
    virtual bool execute();
};

#endif // OUPUTCOMMANDMESSAGESEND_H
