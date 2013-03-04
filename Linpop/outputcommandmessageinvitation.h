#ifndef OUPUTCOMMANDMESSAGEINVITATION_H
#define OUPUTCOMMANDMESSAGEINVITATION_H

#include "protocolcommand.h"

class OutputCommandMessageInvitation : public ProtocolCommand
{
public:
    OutputCommandMessageInvitation();
    virtual bool execute();
};

#endif // OUPUTCOMMANDMESSAGEINVITATION_H
