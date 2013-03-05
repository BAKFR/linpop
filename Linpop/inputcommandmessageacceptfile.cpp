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
    ConversationWindow *conv_win = ptrContactWindow
            ->getConvById(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID());

    int port = protocolCommandParameter.getListProtocolCommandParamText().at(0).getText().toInt();

    //port == 0 -> NO (error ?)

    //TODO
/*

    if (conv_win) {
        new DownloadWindow(conv_win, ptrContactWindow->getNetworkObject(),
                           protocolCommandParameter.getListProtocolCommandParamFile().at(0).getName(),
                           protocolCommandParameter.getListProtocolCommandParamFile().at(0).getSize());
        return true;
    }
    */
    return false;
}

ProtocolCommand *InputCommandMessageAcceptFile::clone()
{
    return new InputCommandMessageAcceptFile(*this);
}
