#include "outputcommandmessageacceptfile.h"

OutputCommandMessageAcceptFile::OutputCommandMessageAcceptFile()
{
}

OutputCommandMessageAcceptFile::OutputCommandMessageAcceptFile(const OutputCommandMessageAcceptFile &ref)
{
    *this = ref;
}

bool OutputCommandMessageAcceptFile::execute()
{
    return true;
}

ProtocolCommand *OutputCommandMessageAcceptFile::clone()
{
    return new OutputCommandMessageAcceptFile(*this);
}
