#ifndef INPUTCOMMANDMESSAGEINVITATION_H
#define INPUTCOMMANDMESSAGEINVITATION_H

#include "protocolcommand.h"

class InputCommandMessageInvitation : public ProtocolCommand
{
public:
    InputCommandMessageInvitation();
    bool execute();
};

#endif // INPUTCOMMANDMESSAGEINVITATION_H
