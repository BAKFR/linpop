#include "inputcommandmessagesend.h"

InputCommandMessageSend::InputCommandMessageSend()
{
}

InputCommandMessageSend::InputCommandMessageSend(const InputCommandMessageSend &ref)
{
    *this = ref;
}

bool InputCommandMessageSend::execute()
{
    qDebug() << "Une commande Send vient d'etre reçue !";
    return true;
}

ProtocolCommand* InputCommandMessageSend::clone()
{
    return new InputCommandMessageSend(*this);
}
