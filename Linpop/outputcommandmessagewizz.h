#ifndef OUTPUTCOMMANDMESSAGEWIZZ_H
#define OUTPUTCOMMANDMESSAGEWIZZ_H

#include "protocolcommand.h"

class OutputCommandMessageWizz : public ProtocolCommand
{
public:
    OutputCommandMessageWizz();
    OutputCommandMessageWizz(const OutputCommandMessageWizz &ref);
    virtual bool execute();
    ProtocolCommand *clone();
};

#endif // OUTPUTCOMMANDMESSAGEWIZZ_H
