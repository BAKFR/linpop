#ifndef PROTOCOLCOMMAND_H
#define PROTOCOLCOMMAND_H

#include "protocolcommandexecutionmode.h"
#include "protocolcommandparameter.h"

class NetworkClient;
class ContactWindow;

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
    static char separator;
    virtual bool execute()=0;
    ProtocolCommand();
    void setExecutionMode(ProtocolCommandExecutionMode executionMode);
    void setContactWindow(ContactWindow *ptrContactWindow);
    ContactWindow *getContactWindow();
    void setInputNetworkClient(NetworkClient *ptrInputNetworkClient);
    void setOutputNetworkClient(NetworkClient *ptrOutputNetworkClient);
    NetworkClient *getInputNetworkClient();
    NetworkClient *getOutputNetworkClient();
    void notifyNetworkClientCommandExecuted();
    ProtocolCommandExecutionMode getExecutionMode();
    bool getValidity();
    ProtocolCommandParameter& getProtocolCommandParameter();
    void setProtocolCommandParameter(ProtocolCommandParameter p);
    virtual ProtocolCommand *clone() = 0;
    virtual ~ProtocolCommand(){}

};

#endif // PROTOCOLCOMMAND_H
