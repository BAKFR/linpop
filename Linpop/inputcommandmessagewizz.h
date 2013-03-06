#ifndef INPUTCOMMANDMESSAGEWIZZ_H
#define INPUTCOMMANDMESSAGEWIZZ_H

#include "protocolcommand.h"

class InputCommandMessageWizz : public ProtocolCommand
{
public:
    InputCommandMessageWizz();
    InputCommandMessageWizz(const InputCommandMessageWizz &ref);
    bool execute();
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGEWIZZ_H
