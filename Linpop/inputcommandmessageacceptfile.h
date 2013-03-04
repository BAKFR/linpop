#ifndef INPUTCOMMANDMESSAGEACCEPTFILE_H
#define INPUTCOMMANDMESSAGEACCEPTFILE_H

#include "protocolcommand.h"

class InputCommandMessageAcceptFile : public ProtocolCommand
{
public:
    InputCommandMessageAcceptFile();
    InputCommandMessageAcceptFile(const InputCommandMessageAcceptFile& ref);
    bool execute();
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGEACCEPTFILE_H
