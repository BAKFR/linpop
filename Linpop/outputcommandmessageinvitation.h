#ifndef OUPUTCOMMANDMESSAGEINVITATION_H
#define OUPUTCOMMANDMESSAGEINVITATION_H

#include "protocolcommand.h"

class OutputCommandMessageInvitation : public ProtocolCommand
{
public:
    OutputCommandMessageInvitation();
    OutputCommandMessageInvitation(const OutputCommandMessageInvitation &ref);
    virtual bool execute();
    QString concatIpAndUsernames(QList<ProtocolCommandParamUser> &list);
    virtual ProtocolCommand *clone();
};

#endif // OUPUTCOMMANDMESSAGEINVITATION_H
