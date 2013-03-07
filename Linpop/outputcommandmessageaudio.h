#ifndef OUTPUTCOMMANDMESSAGEAUDIO_H
#define OUTPUTCOMMANDMESSAGEAUDIO_H

#include "protocolcommand.h"

class OutputCommandMessageAudio : public ProtocolCommand
{
public:
    OutputCommandMessageAudio();
    OutputCommandMessageAudio(const OutputCommandMessageAudio &ref);
    virtual bool execute();
    ProtocolCommand *clone();
};

#endif // OUTPUTCOMMANDMESSAGEAUDIO_H
