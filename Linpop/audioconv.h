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
    void newClient(NetworkClient *client);

signals:
    
public slots:
private:
    AudioOutput *_output_server;
    ConversationWindow *conv;
};

#endif // AUDIOCONV_H
