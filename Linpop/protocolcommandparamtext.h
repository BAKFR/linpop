#ifndef PROTOCOLCOMMANDPARAMTEXT_H
#define PROTOCOLCOMMANDPARAMTEXT_H

#include <QString>

class ProtocolCommandParamText
{
    QString text;
public:
    ProtocolCommandParamText(QString text);
    void setText(QString text);
    QString getText() const;
};

#endif // PROTOCOLCOMMANDPARAMTEXT_H
