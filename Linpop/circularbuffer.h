#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <QByteArray>

class CircularBuffer
{
protected:
    QByteArray byteArray;
public:
    void addData(QByteArray data);
    QString tryToGetCompleteCommand();
};

#endif // CIRCULARBUFFER_H
