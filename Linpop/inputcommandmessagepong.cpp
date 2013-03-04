#include "inputcommandmessagepong.h"

InputCommandMessagePong::InputCommandMessagePong()
{
}

InputCommandMessagePong::InputCommandMessagePong(const InputCommandMessagePong &ref)
{
    *this = ref;
}


bool InputCommandMessagePong::execute()
{
 return true;
}


ProtocolCommand *InputCommandMessagePong::clone()
{
    return new InputCommandMessagePong(*this);
}
