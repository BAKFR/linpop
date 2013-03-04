#ifndef INPUTCOMMANDMESSAGEINVITATION_H
#define INPUTCOMMANDMESSAGEINVITATION_H

#include "protocolcommand.h"

class InputCommandMessageInvitation : public ProtocolCommand
{
public:
    InputCommandMessageInvitation();
    InputCommandMessageInvitation(const InputCommandMessageInvitation &ref);
    bool execute();
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGEINVITATION_H
