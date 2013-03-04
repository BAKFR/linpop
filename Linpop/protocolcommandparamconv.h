#ifndef PROTOCOLCOMMANDPARAMCONV_H
#define PROTOCOLCOMMANDPARAMCONV_H

#include <QString>

class ProtocolCommandParamConv
{
protected:
    QString convID;
public:
    ProtocolCommandParamConv(QString string);
    void setConvID(QString stringID);
    QString getConvID() const;
};

#endif // PROTOCOLCOMMANDPARAMCONV_H
