#include "protocolcommandparamtext.h"

ProtocolCommandParamText::ProtocolCommandParamText(QString text)
{
    this->text = text;
}

void ProtocolCommandParamText::setText(QString text)
{
    this->text = text;
}

QString ProtocolCommandParamText::getText() const
{
    return this->text;
}
