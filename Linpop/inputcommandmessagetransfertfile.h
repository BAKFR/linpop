#ifndef INPUTCOMMANDMESSAGETRANSFERTFILE_H
#define INPUTCOMMANDMESSAGETRANSFERTFILE_H

#include "protocolcommand.h"

class InputCommandMessageTransfertFile : public ProtocolCommand
{
public:
    InputCommandMessageTransfertFile();
    bool execute();
};

#endif // INPUTCOMMANDMESSAGETRANSFERTFILE_H
