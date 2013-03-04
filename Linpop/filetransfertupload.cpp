#include "filetransfertupload.h"
#include "networkobject.h"

#include "protocolcommandparamconv.h"

FileTransfertUpload::FileTransfertUpload(const QFileInfo &info, NetworkObject *net_obj, ConversationWindow *conv)
    : info(info)
{

    ProtocolCommand *cmd = net_obj->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_TRANSFERT_FILE, NULL);
    cmd->getProtocolCommandParameter().addParamCommandConv(ProtocolCommandParamConv(conv->getIDConv()));
    cmd->getProtocolCommandParameter().addParamCommandFile(ProtocolCommandParamFile(info.fileName(), info.size()));

    conv->broadcast(cmd);
}

void    FileTransfertUpload::stop()
{

}

FileTransfertUpload::~FileTransfertUpload()
{

}
