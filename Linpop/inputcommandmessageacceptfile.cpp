#include "inputcommandmessageacceptfile.h"

#include "uploadwindow.h"

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

    UploadWindow *up_win = conv_win->getUploadWindow();
    if (up_win) {
        up_win->onAcceptFile(port, ptrInputNetworkClient);
        return true;
    }
    qDebug() << "We receive an ACCEPT FILE, but there are no UploadWindow.";
    return false;
}

ProtocolCommand *InputCommandMessageAcceptFile::clone()
{
    return new InputCommandMessageAcceptFile(*this);
}
