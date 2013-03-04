#ifndef PROTOCOLCOMMANDPARAMFILE_H
#define PROTOCOLCOMMANDPARAMFILE_H
#include <QString>

class ProtocolCommandParamFile
{
    QString name;
    int size;
public:
    ProtocolCommandParamFile(const QString &string, int size);
    void setName(QString name);
    QString getName();
    void setSize(int size);
    int getSize();
};

#endif // PROTOCOLCOMMANDPARAMFILE_H
