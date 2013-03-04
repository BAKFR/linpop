#include "outputcommandmessagejoin.h"

OutputCommandMessageJoin::OutputCommandMessageJoin()
{
}

OutputCommandMessageJoin::OutputCommandMessageJoin(const OutputCommandMessageJoin&ref)
{
    *this = ref;
}

bool OutputCommandMessageJoin::execute()
{
    return true;
}

ProtocolCommand *OutputCommandMessageJoin::clone()
{
    return new OutputCommandMessageJoin(*this);
}
