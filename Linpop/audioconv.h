#ifndef AUDIOCONV_H
#define AUDIOCONV_H

#include <QObject>

#include "audioinput.h"
#include "audiooutput.h"

class NetworkClient;
class ConversationWindow;

class AudioConv : public QObject
{
    Q_OBJECT
public:
    explicit AudioConv(ConversationWindow *parent = 0);
    void addClient(NetworkClient *client, int port);
signals:
    
public slots:
private:
    AudioOutput *_output_server;
};

#endif // AUDIOCONV_H
