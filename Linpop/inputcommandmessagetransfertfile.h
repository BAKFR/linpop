#ifndef INPUTCOMMANDMESSAGETRANSFERTFILE_H
#define INPUTCOMMANDMESSAGETRANSFERTFILE_H

#include "protocolcommand.h"

class InputCommandMessageTransfertFile : public ProtocolCommand
{
public:
    InputCommandMessageTransfertFile();
    InputCommandMessageTransfertFile(const InputCommandMessageTransfertFile& ref);
    bool execute();
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGETRANSFERTFILE_H
