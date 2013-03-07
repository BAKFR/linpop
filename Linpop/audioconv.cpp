#include "audioconv.h"
#include "networkclient.h"
#include "conversationwindow.h"
#include "protocolinterpretor.h"
#include "contactwindow.h"
#include "networkobject.h"


AudioConv::AudioConv(ConversationWindow *parent) :
    QObject(parent)
{
    _output_server = new AudioOutput(this);

    ProtocolInterpretor &refProtocolInterpretor = parent->getContactWindow()->getNetworkObject()->getProtocolInterpretor();

    ProtocolCommand *command = refProtocolInterpretor.createOutputCommand(COMMAND_MESSAGE_AUDIO, NULL);
    ProtocolCommandParameter p;
    p.addParamCommandConv(ProtocolCommandParamConv(parent->getIDConv()));
    p.addParamCommandText(ProtocolCommandParamText(QString::number(_output_server->getPort())));
    command->setProtocolCommandParameter(p);
    parent->broadcast(command);
}

void AudioConv::addClient(NetworkClient *client, int port)
{
    new AudioInput(this, client->getIP(), port);
}
