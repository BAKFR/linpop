#ifndef INPUTCOMMANDMESSAGEACCEPTFILE_H
#define INPUTCOMMANDMESSAGEACCEPTFILE_H

#include "protocolcommand.h"

class InputCommandMessageAcceptFile : public ProtocolCommand
{
public:
    InputCommandMessageAcceptFile();
    bool execute();
};

#endif // INPUTCOMMANDMESSAGEACCEPTFILE_H
