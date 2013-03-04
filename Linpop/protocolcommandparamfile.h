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
    QString getName() const;
    void setSize(int size);
    int getSize() const;
};

#endif // PROTOCOLCOMMANDPARAMFILE_H
