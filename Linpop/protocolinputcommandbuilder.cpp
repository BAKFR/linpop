#include "protocolinputcommandbuilder.h"
#include "networkclient.h"
#include "corprotocolinputcommandbuilder.h"
#include "networkobject.h"
#include <QByteArray>

ProtocolInputCommandBuilder::ProtocolInputCommandBuilder()
{
    this->ptrCORProtocolInputCommandBuilder = NULL;
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
        command->setContactWindow(this->networkObject->getContactWindow());
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

