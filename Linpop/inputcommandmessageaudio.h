#ifndef INPUTCOMMANDMESSAGEAUDIO_H
#define INPUTCOMMANDMESSAGEAUDIO_H

#include "protocolcommand.h"

class InputCommandMessageAudio : public ProtocolCommand
{
public:
    InputCommandMessageAudio();
    InputCommandMessageAudio(const InputCommandMessageAudio &ref);
    bool execute();
    ProtocolCommand *clone();
};

#endif // INPUTCOMMANDMESSAGEAUDIO_H
