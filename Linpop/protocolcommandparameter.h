#ifndef PROTOCOLCOMMANDPARAMETER_H
#define PROTOCOLCOMMANDPARAMETER_H

#include <QList>
#include "protocolcommandparamconv.h"
#include "protocolcommandparamfile.h"
#include "protocolcommandparamtext.h"
#include "protocolcommandparamuser.h"

class ProtocolCommandParameter
{
    QList<ProtocolCommandParamUser> listProtocolCommandParamUser;
    QList<ProtocolCommandParamFile> listProtocolCommandParamFile;
    QList<ProtocolCommandParamText> listProtocolCommandParamText;
    QList<ProtocolCommandParamConv> listProtocolCommandParamConv;
public:
    ProtocolCommandParameter();
    QList<ProtocolCommandParamUser>& getListProtocolCommandParamUser();
    QList<ProtocolCommandParamFile>& getListProtocolCommandParamFile();
    QList<ProtocolCommandParamText>& getListProtocolCommandParamText();
    QList<ProtocolCommandParamConv>& getListProtocolCommandParamConv();
    void addParamCommandUser(ProtocolCommandParamUser p);
    void addParamCommandFile(ProtocolCommandParamFile p);
    void addParamCommandText(ProtocolCommandParamText p);
    void addParamCommandConv(ProtocolCommandParamConv p);
};

#endif // PROTOCOLCOMMANDPARAMETER_H
