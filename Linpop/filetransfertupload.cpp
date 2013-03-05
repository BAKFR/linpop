#include "filetransfertupload.h"
#include "networkobject.h"

#include "protocolcommandparamconv.h"

FileTransfertUpload::FileTransfertUpload(const QFileInfo &info, NetworkObject *net_obj, ConversationWindow *conv)
    : info(info), _total(0), _completed(0), _errors(0)
{

    ProtocolCommand *cmd = net_obj->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_TRANSFERT_FILE, NULL);
    cmd->getProtocolCommandParameter().addParamCommandConv(ProtocolCommandParamConv(conv->getIDConv()));
    cmd->getProtocolCommandParameter().addParamCommandFile(ProtocolCommandParamFile(info.fileName(), info.size()));

    conv->broadcast(cmd);

//    _total = conv->getNbMembers();
}

void    FileTransfertUpload::stop()
{

}

FileTransfertUpload::~FileTransfertUpload()
{

}
