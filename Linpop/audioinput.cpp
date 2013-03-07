#include "audioinput.h"
#include <QTimer>

AudioInput::AudioInput(QObject *parent, const QString &ip, quint16 port) :
    QObject(parent), _socket(this), _audio_output(NULL)
{
    connect(&_socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    connect(&_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError()));
    _socket.connectToHost(ip, port);
}

AudioInput::~AudioInput() {
    if (_audio_output)
        _audio_output->deleteLater();
    qDebug() << "WHAT";
}

void AudioInput::onSocketConnected() {

    QAudioFormat format;
    // Set up the format, eg.
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    qDebug() << QAudioDeviceInfo::defaultOutputDevice().deviceName();
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format)) {
        qWarning() << "raw audio format not supported by backend, cannot play audio.";
        return;
    }

    _audio_output = new QAudioOutput(format, NULL);
    connect(_audio_output, SIGNAL(stateChanged(QAudio::State)), SLOT(onAudioChange(QAudio::State)));

    QTimer::singleShot(1000,this,SLOT(startAudio()));
}

void AudioInput::onSocketError() {
    qDebug() << "ERROR SOCKET" << _socket.errorString();
    deleteLater();
}

void AudioInput::onAudioChange(QAudio::State state) {
    qDebug() << ":)" << state;
    if (state == QAudio::StoppedState) {
        if (_socket.isReadable())
            QTimer::singleShot(1000,this,SLOT(startAudio()));
        else
           deleteLater();
    }
}

void AudioInput::startAudio() {
    _audio_output->start(&_socket);
}
