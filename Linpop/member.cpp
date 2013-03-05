#include "member.h"

Member::Member()
{

}

Member::Member(int idUser, int idMember, QString name, QString ip, int idConversation):
    _idUser(idUser),
    _idMember(idMember),
    _name(name),
    _ip(ip),
    _idConversation(idConversation)
{

}

Member::~Member()
{

}

int     Member::getIdUser()
{
    return(this->_idUser);
}

int     Member::getIdMember()
{
    return(this->_idMember);
}

QString Member::getName()
{
    return(this->_name);
}

QString Member::getIp()
{
    return(this->_ip);
}

int     Member::getIdConversation()
{
    return(this->_idConversation);
}

void    Member::setInfo(int idUser, int idMember, QString name, QString ip, int idConversation)
{
    this->_idUser = idUser;
    this->_idMember = idMember;
    this->_name = name;
    this->_ip = ip;
    this->_idConversation = idConversation;
}
