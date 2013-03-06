#include "inputcommandmessagewizz.h"
#include "contactwindow.h"
#include "conversationwindow.h"
#include <QDebug>

InputCommandMessageWizz::InputCommandMessageWizz()
{
}

InputCommandMessageWizz::InputCommandMessageWizz(const InputCommandMessageWizz &ref)
{
    *this = ref;
}

bool InputCommandMessageWizz::execute()
{
    QString message;

    ConversationWindow *conv_win = ptrContactWindow
            ->getConvById(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID());
    if (conv_win) {
        conv_win->receiveWizz();
        return true;
    } else {
        qDebug() << "ERROR: we receive a wizz from an unknown conversation";
        return false;
    }
}

ProtocolCommand* InputCommandMessageWizz::clone()
{
    return new InputCommandMessageWizz(*this);
}
