#include "contact.h"

Contact::Contact()
{
}

Contact::~Contact()
{
}

QString Contact::getContactName()
{
    return (this->_contactName);
}

QString Contact::getIp()
{
    return (this->_ip);
}

int     Contact::getIdContact()
{
    return (this->_idContact);
}

int     Contact::getIdUser()
{
    return (this->_idUser);
}


void    Contact::setInfo(int idUser, int idContact, QString contactName, QString ip)
{
    this->_idUser = idUser;
    this->_idContact = idContact;
    this->_contactName = contactName;
    this->_ip = ip;
}
