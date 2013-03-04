#include "inputcommandmessagetransfertfile.h"

InputCommandMessageTransfertFile::InputCommandMessageTransfertFile()
{
}

InputCommandMessageTransfertFile::InputCommandMessageTransfertFile(const InputCommandMessageTransfertFile& ref)
{
    *this = ref;
}

bool InputCommandMessageTransfertFile::execute()
{
    return true;
}

ProtocolCommand *InputCommandMessageTransfertFile::clone()
{
    return new InputCommandMessageTransfertFile(*this);
}
