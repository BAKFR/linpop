#ifndef PROTOCOLCOMMANDPARAMFILE_H
#define PROTOCOLCOMMANDPARAMFILE_H
#include <QString>

class ProtocolCommandParamFile
{
    QString name;
    int size;
    int port;
public:
    ProtocolCommandParamFile(QString string, int size, int port);
    void setName(QString name);
    QString getName();
    void setSize(int size);
    int getSize();
    void setPort(int port);
    int getPort();
};

#endif // PROTOCOLCOMMANDPARAMFILE_H
