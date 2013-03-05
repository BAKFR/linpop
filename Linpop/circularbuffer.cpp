#include "circularbuffer.h"
#include <QString>
#include <QByteArray>

CircularBuffer::CircularBuffer(QObject *parent)
{

}

void CircularBuffer::initialize()
{
}

void CircularBuffer::addData(QByteArray data)
{
    byteArray.append(data);
}

QString CircularBuffer::tryToGetCompleteCommand()
{
    if (byteArray.contains("\r\n"))
    {
        int index;
        index = byteArray.indexOf("\r\n");
        QByteArray query = byteArray.left(index);
        byteArray.remove(0, index + 2);
        return QString::fromUtf8(query);
    }
    else
    {
        return "";
    }
}
