#include "outputcommandmessagetransfertfile.h"

OutputCommandMessageTransfertFile::OutputCommandMessageTransfertFile()
{
}

OutputCommandMessageTransfertFile::OutputCommandMessageTransfertFile(const OutputCommandMessageTransfertFile &ref)
{
    *this = ref;
}

bool OutputCommandMessageTransfertFile::execute()
{
    return true;
}

ProtocolCommand *OutputCommandMessageTransfertFile::clone()
{
    return new OutputCommandMessageTransfertFile(*this);
}
