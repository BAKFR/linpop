#include "ouputcommandmessagesend.h"


OutputCommandMessageSend::OutputCommandMessageSend()
{
}

OutputCommandMessageSend::OutputCommandMessageSend(const OutputCommandMessageSend &ref)
{
    *this = ref;
}

bool OutputCommandMessageSend::execute()
{
    return true;
}

ProtocolCommand *OutputCommandMessageSend::clone()
{
    return new OutputCommandMessageSend(*this);
}
