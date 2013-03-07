#include "inputcommandmessageaudio.h"
#include "contactwindow.h"
#include "conversationwindow.h"
#include "networkclient.h"
#include "database.h"
#include <QDebug>

InputCommandMessageAudio::InputCommandMessageAudio()
{
}

InputCommandMessageAudio::InputCommandMessageAudio(const InputCommandMessageAudio &ref)
{
    *this = ref;
}

bool InputCommandMessageAudio::execute()
{
    QString message;

    ConversationWindow *conv_win = ptrContactWindow
            ->getConvById(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID());
    if (conv_win) {

        int port = protocolCommandParameter.getListProtocolCommandParamText().at(0).getText().toInt();
        conv_win->startAudio(ptrInputNetworkClient, port);

        return true;
    } else {
        qDebug() << "ERROR: we receive AUDIO from a unknown ";
        return false;
    }
}

ProtocolCommand* InputCommandMessageAudio::clone()
{
    return new InputCommandMessageAudio(*this);
}
