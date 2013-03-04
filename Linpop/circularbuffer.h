#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <QByteArray>
#include <QObject>

class CircularBuffer
{
protected:
    QByteArray byteArray;
public:
    explicit CircularBuffer(QObject *parent = 0);
    void initialize();
    void addData(QByteArray data);
    QString tryToGetCompleteCommand();
};

#endif // CIRCULARBUFFER_H
