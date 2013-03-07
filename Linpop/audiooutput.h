#ifndef AUDIOOUTPUT_H
#define AUDIOOUTPUT_H

#include <QObject>
#include <QTcpServer>
#include <QAudioInput>

class AudioOutput : public QObject
{
    Q_OBJECT
public:
    explicit AudioOutput(QObject *parent = 0);
    ~AudioOutput();
    int getPort();
signals:
    
public slots:
    void onServerConnection();
    void onAudioChange(QAudio::State state);
private:
    QTcpServer  _server;
    QAudioInput *_audio_input;
};

#endif // AUDIOOUTPUT_H
