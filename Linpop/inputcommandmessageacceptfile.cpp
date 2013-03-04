#include "inputcommandmessageacceptfile.h"

InputCommandMessageAcceptFile::InputCommandMessageAcceptFile()
{
}

InputCommandMessageAcceptFile::InputCommandMessageAcceptFile(const InputCommandMessageAcceptFile& ref)
{
    *this = ref;
}

bool InputCommandMessageAcceptFile::execute()
{
    return true;
}

ProtocolCommand *InputCommandMessageAcceptFile::clone()
{
    return new InputCommandMessageAcceptFile(*this);
}
