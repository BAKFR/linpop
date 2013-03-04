#ifndef PROTOCOLCOMMAND_H
#define PROTOCOLCOMMAND_H

#include "protocolcommandexecutionmode.h"
#include "protocolcommandparameter.h"
#include "networkclient.h"
#include "contactwindow.h"

//class NetworkClient;

class ProtocolCommand
{
protected:
    ProtocolCommandExecutionMode executionMode;
    NetworkClient *ptrOutputNetworkClient;
    NetworkClient *ptrInputNetworkClient;
    ContactWindow *ptrContactWindow;
    bool validity;
    ProtocolCommandParameter protocolCommandParameter;
public:
    virtual bool execute()=0;
    ProtocolCommand();
    void setExecutionMode(ProtocolCommandExecutionMode executionMode);
    void setContactWindow(ContactWindow *ptrContactWindow);
    ContactWindow *getContactWindow();
    void setInputNetworkClient(NetworkClient *ptrInputNetworkClient);
    void setOutputNetworkClient(NetworkClient *ptrOutputNetworkClient);
    NetworkClient *getInputNetworkClient();
    NetworkClient *getOutputNetworkClient();
    void onNetworkClientCloseNotification(NetworkClient *client);
    void abord();
    void notifyNetworkClientCommandExecuted();
    ProtocolCommandExecutionMode getExecutionMode();
    bool getValidity();
    ProtocolCommandParameter& getProtocolCommandParameter();
    void setProtocolCommandParameter(ProtocolCommandParameter p);
    virtual ~ProtocolCommand(){}

};

#endif // PROTOCOLCOMMAND_H
