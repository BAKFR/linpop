#include "protocolcommand.h"

QString ProtocolCommand::separator = "\01";
QString ProtocolCommand::separator_telnet = ":";

ProtocolCommand::ProtocolCommand()
    : ptrOutputNetworkClient(NULL), ptrInputNetworkClient(NULL),
      ptrContactWindow(NULL), validity(true)
{
}

void ProtocolCommand::setExecutionMode(ProtocolCommandExecutionMode executionMode)
{
    this->executionMode = executionMode;
}

void ProtocolCommand::setContactWindow(ContactWindow *ptrContactWindow)
{
    this->ptrContactWindow = ptrContactWindow;
}

ContactWindow *ProtocolCommand::getContactWindow()
{
   return this->ptrContactWindow;
}

void ProtocolCommand::setInputNetworkClient(NetworkClient *ptrInputNetworkClient)
{
   this->ptrInputNetworkClient = ptrInputNetworkClient;
}

void ProtocolCommand::setOutputNetworkClient(NetworkClient *ptrOutputNetworkClient)
{
    this->ptrOutputNetworkClient = ptrOutputNetworkClient;
}

NetworkClient *ProtocolCommand::getInputNetworkClient()
{
    return this->ptrInputNetworkClient;
}

NetworkClient *ProtocolCommand::getOutputNetworkClient()
{
    return this->ptrOutputNetworkClient;
}

void ProtocolCommand::onNetworkClientCloseNotification(NetworkClient *client)
{
    this->abord();
}

void ProtocolCommand::abord()
{
  this->validity = false;
}

void ProtocolCommand::notifyNetworkClientCommandExecuted()
{
    if (this->ptrInputNetworkClient != NULL)
    {
        this->ptrInputNetworkClient->onNetworkSocketNotifyCommandExecuted(this);
    }
    if (this->ptrOutputNetworkClient != NULL)
    {
        this->ptrOutputNetworkClient->onNetworkSocketNotifyCommandExecuted(this);
    }
}

ProtocolCommandExecutionMode ProtocolCommand::getExecutionMode()
{
    return this->executionMode;
}

bool ProtocolCommand::getValidity()
{
    return this->validity;
}

ProtocolCommandParameter& ProtocolCommand::getProtocolCommandParameter()
{
    return this->protocolCommandParameter;
}

void ProtocolCommand::setProtocolCommandParameter(ProtocolCommandParameter p)
{
    this->protocolCommandParameter = p;
}
