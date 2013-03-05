#include "user.h"

User::User()
{
}

User::User(int idUser, QString userName, QString password):
    _idUser(idUser),
    _userName(userName),
    _password(password)
{

}

User::~User()
{

}

int     User::getIdUser()
{
    return(this->_idUser);
}

QString User::getUserName()
{
    return(this->_userName);
}

QString User::getPassword()
{
    return(this->_password);
}

void    User::setInfo(int idUser, QString userName, QString password)
{
    this->_idUser = idUser;
    this->_userName = userName;
    this->_password = password;
}
