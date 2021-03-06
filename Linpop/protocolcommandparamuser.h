#ifndef PROTOCOLCOMMANDPARAMUSER_H
#define PROTOCOLCOMMANDPARAMUSER_H

#include <QString>

class ProtocolCommandParamUser
{
    QString username;
    QString ip;
public:
    ProtocolCommandParamUser(QString username, QString ip);
    void setUsername(QString username);
    QString getUsername() const;
    void setIP(QString ip);
    QString getIP() const;
};

#endif // PROTOCOLCOMMANDPARAMUSER_H
