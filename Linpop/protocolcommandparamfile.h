#ifndef PROTOCOLCOMMANDPARAMFILE_H
#define PROTOCOLCOMMANDPARAMFILE_H
#include <QString>

class ProtocolCommandParamFile
{
    QString name;
    qulonglong size;
public:
    ProtocolCommandParamFile(const QString &string, qulonglong size);
    void setName(QString name);
    QString getName() const;
    void setSize(qulonglong size);
    qulonglong getSize() const;
};

#endif // PROTOCOLCOMMANDPARAMFILE_H
