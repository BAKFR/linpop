#include "inputcommandmessagetransfertfile.h"

#include "downloadwindow.h"

InputCommandMessageTransfertFile::InputCommandMessageTransfertFile()
{
}

InputCommandMessageTransfertFile::InputCommandMessageTransfertFile(const InputCommandMessageTransfertFile& ref)
{
    *this = ref;
}

bool InputCommandMessageTransfertFile::execute()
{
    /*
     *répercuter la commande sur l'app.
     */

    ConversationWindow *conv_win = ptrContactWindow
            ->getConvById(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID());

    if (conv_win) {
        new DownloadWindow(conv_win, ptrContactWindow->getNetworkObject(),
                           protocolCommandParameter.getListProtocolCommandParamFile().at(0).getName(),
                           protocolCommandParameter.getListProtocolCommandParamFile().at(0).getSize());
        return true;
    }
    return false;
}

ProtocolCommand *InputCommandMessageTransfertFile::clone()
{
    return new InputCommandMessageTransfertFile(*this);
}