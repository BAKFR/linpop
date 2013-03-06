#include "outputcommandmessageinvitation.h"
#include "networkclient.h"

OutputCommandMessageInvitation::OutputCommandMessageInvitation()
{
}

OutputCommandMessageInvitation::OutputCommandMessageInvitation(const OutputCommandMessageInvitation& ref)
{
    *this = ref;
}

QString OutputCommandMessageInvitation::concatIpAndUsernames(QList<ProtocolCommandParamUser> &list)
{
    int i = 0;
    QString concat;
    bool first = true;
    while (i < list.size())
    {
        if (first)
        {
            concat+=list.at(i).getIP()+ProtocolCommand::separator+list.at(i).getUsername();
            first = false;
        }
        else
        {
		  concat += ProtocolCommand::separator + list.at(i).getIP()+ProtocolCommand::separator+list.at(i).getUsername();
        }
        i++;
    }
    return concat;
}

bool OutputCommandMessageInvitation::execute()
{
    QString invite = QString("INVITE") + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
            + ProtocolCommand::separator + concatIpAndUsernames(protocolCommandParameter.getListProtocolCommandParamUser()) + "\r\n";
    return ptrOutputNetworkClient->getTcpSocket()->write(invite.toUtf8()) > 0;
}

ProtocolCommand *OutputCommandMessageInvitation::clone()
{

    return new OutputCommandMessageInvitation(*this);
}
