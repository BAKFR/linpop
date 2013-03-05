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
    qDebug()<<"Une commande pong vient d'etre recue !";
 return true;
}


ProtocolCommand *InputCommandMessagePong::clone()
{
    return new InputCommandMessagePong(*this);
}
