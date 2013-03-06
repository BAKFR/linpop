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

void    Contact::setIdUser(int &idUser)
{
    this->_idUser = idUser;
}

void    Contact::setIdContact(int &idContact)
{
    this->_idContact = idContact;
}

void    Contact::setContactName(QString &contactName)
{
    this->_contactName = contactName;
}

void    Contact::setIp(QString &ip)
{
    this->_ip = ip;
}

void    Contact::setInfo(int idUser, int idContact, QString contactName, QString ip)
{
    this->_idUser = idUser;
    this->_idContact = idContact;
    this->_contactName = contactName;
    this->_ip = ip;
}
