#include "inputcommandmessagejoin.h"

InputCommandMessageJoin::InputCommandMessageJoin()
{
}

InputCommandMessageJoin::InputCommandMessageJoin(const InputCommandMessageJoin& ref)
{
    *this = ref;
}

bool InputCommandMessageJoin::execute()
{
    return true;
}

ProtocolCommand* InputCommandMessageJoin::clone()
{
    return new InputCommandMessageJoin(*this);
}
