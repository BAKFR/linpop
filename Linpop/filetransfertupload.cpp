#include "filetransfertupload.h"
#include "networkobject.h"

#include "protocolcommandparamconv.h"

FileTransfertUpload::FileTransfertUpload(const QFileInfo &info, NetworkObject *net_obj, ConversationWindow *conv)
    : info(info), _total(0), _completed(0), _errors(0), _file(NULL)
{

    ProtocolCommand *cmd = net_obj->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_TRANSFERT_FILE, NULL);
    cmd->getProtocolCommandParameter().addParamCommandConv(ProtocolCommandParamConv(conv->getIDConv()));
    cmd->getProtocolCommandParameter().addParamCommandFile(ProtocolCommandParamFile(info.fileName(), info.size()));

    conv->broadcast(cmd);

    _total = conv->getNbMembers();
}

FileTransfertUpload::~FileTransfertUpload()
{
    delete _file;
}

void FileTransfertUpload::receiveAcceptFile(NetworkClient *client, int port)
{
    if (port == 0) {
        _errors++;
        emit clientError("Client reject file.");
        check_nbr();
    } else {
        QTcpSocket *socket = new QTcpSocket(this);

        socket->connectToHost(client->getTcpSocket()->peerAddress(), port);
        connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
        connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(onSocketWritten()));
    }
}

void    FileTransfertUpload::onSocketConnected()
{
    if (_file == NULL) {
        _file = new QFile(info.filePath());
        _file->open(QIODevice::ReadOnly);
    } else {
        _file->reset();
    }

    QTcpSocket *socket = dynamic_cast<QTcpSocket*>(sender());
    if (_file->error()) {
        emit error(_file->errorString());
        socket->deleteLater();
    }
    socket->write(_file->readAll());
    if (_file->error()) {
        emit error(_file->errorString());
        socket->deleteLater();
    }
}

void    FileTransfertUpload::onSocketError(QAbstractSocket::SocketError)
{
    sender()->deleteLater();
    _errors++;
    emit clientError("Client reject file.");
    check_nbr();
}

void    FileTransfertUpload::onSocketWritten()
{
    QTcpSocket *socket = dynamic_cast<QTcpSocket*>(sender());

    if (socket->bytesToWrite() == 0) {
        socket->close();
        socket->deleteLater();
        _completed++;
        check_nbr();
    }
}

void    FileTransfertUpload::check_nbr()
{
    emit progress(_completed, _errors, _total);
    if (_completed + _errors >= _total)
        emit complete(_completed, _errors, _total);
}

int FileTransfertUpload::getTotal() const
{
    return _total;
}
