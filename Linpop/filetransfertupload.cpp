#include "filetransfertupload.h"
#include "networkobject.h"

#include "protocolcommandparamconv.h"

FileTransfertUpload::FileTransfertUpload(const QFileInfo &info, NetworkObject *net_obj, ConversationWindow *conv)
    : info(info), _total(0), _completed(0), _errors(0)
{

    ProtocolCommand *cmd = net_obj->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_TRANSFERT_FILE, NULL);
    cmd->getProtocolCommandParameter().addParamCommandConv(ProtocolCommandParamConv(conv->getIDConv()));
    cmd->getProtocolCommandParameter().addParamCommandFile(ProtocolCommandParamFile(info.fileName(), info.size()));

    conv->broadcast(cmd);

    _total = conv->getNbMembers();
}

FileTransfertUpload::~FileTransfertUpload()
{

}

void FileTransfertUpload::receiveAcceptFile(NetworkClient *client, int port)
{
    if (port == 0) {
        _errors++;
        emit clientError("Client reject file.");
        check_nbr();
    } else {
        //création de socket
        //et+
        QTcpSocket *socket = new QTcpSocket(this);

        socket->connectToHost(client->getTcpSocket()->peerAddress(), port);
        connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
        connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(onSocketWritten()));
    }
}

void    FileTransfertUpload::onSocketConnected()
{
    //TODO
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
    //TODO
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
