#include "audiooutput.h"
#include <QTcpSocket>

AudioOutput::AudioOutput(QObject *parent) :
    QObject(parent), _server(), _audio_input(NULL)
{
    connect(&_server, SIGNAL(newConnection()), this, SLOT(onServerConnection()));
    _server.listen();
   qDebug() <<  _server.serverPort();
}

AudioOutput::~AudioOutput() {

}

int AudioOutput::getPort() {
    return _server.serverPort();
}

void AudioOutput::onServerConnection() {
//    _server.

    QTcpSocket *socket = _server.nextPendingConnection();

    socket->setParent(this);

    QAudioFormat format;
    // set up the format you want, eg.
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
     qWarning() << "default format not supported try to use nearest";
     format = info.nearestFormat(format);
    }
    _audio_input = new QAudioInput(format, this);
    connect(_audio_input, SIGNAL(stateChanged(QAudio::State)), this, SLOT(onAudioChange(QAudio::State)));

    _audio_input->start(socket);
    // Records audio for 3000ms

}

void AudioOutput::onAudioChange(QAudio::State state)
{
    if (state == QAudio::StoppedState)
        deleteLater();
}
