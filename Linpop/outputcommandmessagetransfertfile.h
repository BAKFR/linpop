#ifndef OUTPUTCOMMANDMESSAGETRANSFERTFILE_H
#define OUTPUTCOMMANDMESSAGETRANSFERTFILE_H

#include "protocolcommand.h"

class OutputCommandMessageTransfertFile :  public ProtocolCommand
{
public:
    OutputCommandMessageTransfertFile();
    virtual bool execute();
};

#endif // OUTPUTCOMMANDMESSAGETRANSFERTFILE_H
