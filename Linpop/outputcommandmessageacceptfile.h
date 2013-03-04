#ifndef OUTPUTCOMMANDMESSAGEACCEPTFILE_H
#define OUTPUTCOMMANDMESSAGEACCEPTFILE_H
#include "protocolcommand.h"

class OutputCommandMessageAcceptFile : public ProtocolCommand
{
public:
    OutputCommandMessageAcceptFile();
    OutputCommandMessageAcceptFile(const OutputCommandMessageAcceptFile &ref);
    virtual bool execute();
    virtual ProtocolCommand* clone();
};

#endif // OUTPUTCOMMANDMESSAGEACCEPTFILE_H
