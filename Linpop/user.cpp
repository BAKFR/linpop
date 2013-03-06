#include "user.h"

User::User()
{
}

User::User(QString userName, QString password):
    _userName(userName),
    _password(password)
{

}

User::~User()
{

}

QString User::getUserName()
{
    return(this->_userName);
}

QString User::getPassword()
{
    return(this->_password);
}

int    User::getIdUser()
{
    return (this->_idUser);
}

void    User::setUserName(QString &other)
{
    this->_userName = other;
}

void    User::setPassword(QString &other)
{
    this->_password = other;
}

void    User::setIdUser(int &other)
{
    this->_idUser = other;
}

void    User::setInfo(QString &userName, QString &password)
{
    this->_userName = userName;
    this->_password = password;
}
