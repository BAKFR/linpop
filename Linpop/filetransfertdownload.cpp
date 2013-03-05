#include "filetransfertdownload.h"

#include "protocolcommand.h"
#include "protocolinterpretor.h"
#include "networkobject.h"

FileTransfertDownload::FileTransfertDownload(NetworkObject *net_obj, const QString &conv_id, NetworkClient *target, const QString &path_file, int size)
    : _server(NULL), _socket(NULL), _file(NULL), _current_size(0), _total_size(size)
{

    _file = new QFile(path_file);

    _server = new QTcpServer();
    _server->listen();
    connect(_server, SIGNAL(newConnection()), this, SLOT(onSocketOpen()));


    ProtocolCommand *cmd = net_obj->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_ACCEPT_FILE, target);
    cmd->getProtocolCommandParameter().addParamCommandConv(ProtocolCommandParamConv(conv_id));
    cmd->getProtocolCommandParameter().addParamCommandText(ProtocolCommandParamText(QString::number(_server->serverPort())));

    net_obj->getProtocolInterpretor().executeCommand(cmd);
}

FileTransfertDownload::~FileTransfertDownload()
{
    delete _server;
    delete _socket;
    delete _file;
}

void FileTransfertDownload::stop()
{
    delete _socket;
    delete _file;
    _socket = NULL;
    _file = NULL;
}

void FileTransfertDownload::reject(NetworkObject *net_obj, const QString &conv_id, NetworkClient *target)
{
    //send NO

    ProtocolCommand *cmd = net_obj->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_ACCEPT_FILE, target);
    cmd->getProtocolCommandParameter().addParamCommandConv(ProtocolCommandParamConv(conv_id));
    cmd->getProtocolCommandParameter().addParamCommandText(ProtocolCommandParamText("0"));

    net_obj->getProtocolInterpretor().executeCommand(cmd);
}

void FileTransfertDownload::onSocketOpen()
{
    _socket = _server->nextPendingConnection();
    _socket->setParent(NULL);
    _server->deleteLater();
    _server = NULL;
    connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));

    if (!_file->open( QIODevice::WriteOnly | QIODevice::Truncate)) {
        _socket->deleteLater();
        _socket = NULL;
        emit error(_file->errorString());
    } else
        emit start();
}

void FileTransfertDownload::onSocketError(QAbstractSocket::SocketError err)
{
    if (err != QAbstractSocket::RemoteHostClosedError)
        emit error(_socket->errorString());
}

void FileTransfertDownload::onSocketDisconnected()
{
    _file->close();

    if (_current_size == _total_size)
        emit complete();
    else
        emit error("Bad size file");

    _socket->deleteLater();
    _socket = NULL;
    _file->deleteLater();
    _file = NULL;
}

void FileTransfertDownload::onSocketReadyRead()
{
    char data[1024];
    int readed = -1, result = -1;

    while (_socket->bytesAvailable() > 0 && (readed = _socket->read(data, 1024)) > 0) {
        result = _file->write(data, readed);
        if (result == -1) {
            _socket->deleteLater();
            _socket = NULL;
            emit error(_file->errorString());
            _file->deleteLater();
            _file = NULL;
        }

        _current_size += readed;
    }
    if (readed == -1) {
        _socket->deleteLater();
        _socket = NULL;
        _file->deleteLater();
        _file = NULL;
    }
    emit progress(_current_size, _total_size);
}

