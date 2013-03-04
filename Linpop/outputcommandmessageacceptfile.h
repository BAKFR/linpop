#ifndef OUTPUTCOMMANDMESSAGEACCEPTFILE_H
#define OUTPUTCOMMANDMESSAGEACCEPTFILE_H
#include "protocolcommand.h"

class OutputCommandMessageAcceptFile : public ProtocolCommand
{
public:
    OutputCommandMessageAcceptFile();
    virtual bool execute();
};

#endif // OUTPUTCOMMANDMESSAGEACCEPTFILE_H
