#include "protocolcommandparamuser.h"

ProtocolCommandParamUser::ProtocolCommandParamUser(QString username, QString ip)
{
    this->ip = ip;
    this->username = username;
}

void ProtocolCommandParamUser::setUsername(QString username)
{
    this->username = username;
}

QString ProtocolCommandParamUser::getUsername() const
{
    return this->username;
}

void ProtocolCommandParamUser::setIP(QString ip)
{
    this->ip = ip;
}

QString ProtocolCommandParamUser::getIP() const
{
    return this->ip;
}
