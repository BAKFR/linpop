#include "protocolinputcommandbuilder.h"
#include "networkclient.h"
#include "corprotocolinputcommandbuilder.h"
#include "networkobject.h"
#include "corcommandmessagedeconnection.h"
#include "corcommandmessagepong.h"
#include "corcommandmessagejoin.h"
#include "corcommandmessageacceptfile.h"
#include "corcommandmessageinvitation.h"
#include "corcommandmessageping.h"
#include "corcommandmessagesend.h"
#include "corcommandmessagetransfertfile.h"

#include <QByteArray>

ProtocolInputCommandBuilder::ProtocolInputCommandBuilder()
{
    this->ptrCORProtocolInputCommandBuilder = NULL;
    CORProtocolInputCommandBuilder *maillon;

    maillon = new CORCommandMessageDeconnection();
    this->addCOR(maillon);
    maillon = new CORCommandMessagePong();
    this->addCOR(maillon);
    maillon = new CORCommandMessageJoin();
    this->addCOR(maillon);
    maillon = new CORCommandMessageAcceptFile();
    this->addCOR(maillon);
    maillon = new CORCommandMessageInvitation();
    this->addCOR(maillon);
    maillon = new CORCommandMessagePing();
    this->addCOR(maillon);
    maillon = new CORCommandMessageSend();
    this->addCOR(maillon);
    maillon = new CORCommandMessageTransfertFile();
    this->addCOR(maillon);
}

ProtocolCommand *ProtocolInputCommandBuilder::build(QByteArray query, NetworkClient *client)
{
    if (this->ptrCORProtocolInputCommandBuilder == NULL)
    {
        return NULL;
    }
    else
    {
        ProtocolCommand *command = this->ptrCORProtocolInputCommandBuilder->find(query);
        if (!command)
            return NULL;
        command->setContactWindow(this->networkObject->getContactWindow());
        command->setInputNetworkClient(client);
        return command;
    }
}

void ProtocolInputCommandBuilder::initialize(NetworkObject *no)
{
    this->networkObject = no;
}

void ProtocolInputCommandBuilder::addCOR(CORProtocolInputCommandBuilder *cor)
{
    CORProtocolInputCommandBuilder *iterator;

    if (this->ptrCORProtocolInputCommandBuilder == NULL)
    {
        this->ptrCORProtocolInputCommandBuilder = cor;
    }
    else
    {
        iterator = this->ptrCORProtocolInputCommandBuilder;
        while (iterator->getNext() != NULL)
        {
            iterator = iterator->getNext();
        }
        iterator->setNext(cor);
    }
}

