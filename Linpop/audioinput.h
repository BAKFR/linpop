#ifndef AUDIOINPUT_H
#define AUDIOINPUT_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QAudioOutput>


class AudioInput : public QObject
{
    Q_OBJECT
public:
    explicit AudioInput(QObject *parent, const QString &ip, quint16 port);
    ~AudioInput();
signals:
    
public slots:
    void onSocketConnected();
    void onSocketError();
    void onAudioChange(QAudio::State state);

    void startAudio();
private:
    QTcpSocket      _socket;
    QAudioOutput    *_audio_output;
};

#endif // AUDIOINPUT_H
