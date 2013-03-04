#ifndef OUTPUTCOMMANDMESSAGETRANSFERTFILE_H
#define OUTPUTCOMMANDMESSAGETRANSFERTFILE_H

#include "protocolcommand.h"

class OutputCommandMessageTransfertFile :  public ProtocolCommand
{
public:
    OutputCommandMessageTransfertFile();
    OutputCommandMessageTransfertFile(const OutputCommandMessageTransfertFile &ref);
    virtual bool execute();
    virtual ProtocolCommand *clone();
};

#endif // OUTPUTCOMMANDMESSAGETRANSFERTFILE_H
