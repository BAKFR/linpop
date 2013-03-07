#include "inputcommandmessagesend.h"
#include "contactwindow.h"
#include "conversationwindow.h"
#include "networkclient.h"
#include "database.h"
#include <QDebug>

InputCommandMessageSend::InputCommandMessageSend()
{
}

InputCommandMessageSend::InputCommandMessageSend(const InputCommandMessageSend &ref)
{
    *this = ref;
}

bool InputCommandMessageSend::execute()
{
    QString message;

    ConversationWindow *conv_win = ptrContactWindow
            ->getConvById(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID());
    if (conv_win) {
        message = this->ptrInputNetworkClient->getUsername() + QString(" dit: ") + protocolCommandParameter.getListProtocolCommandParamText().at(0).getText();
        conv_win->AddText(message);
        this->ptrContactWindow->getDatabase()->setHistory(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID().toInt(), message);
        return true;
    } else {
        qDebug() << "ERROR: we receive msg from a unknown ";
        return false;
    }
}

ProtocolCommand* InputCommandMessageSend::clone()
{
    return new InputCommandMessageSend(*this);
}
