#ifndef MEMBER_H
#define MEMBER_H

#include <QMainWindow>
#include "conversation.h"

class Member
{
    int     _idUser;
    int     _idMember;
    QString _name;
    QString _ip;
    int     _idConversation;

public:
    Member();
    Member(int idUser, int idMember, QString name, QString ip, int idConversation);
    ~Member();

public:
    int     getIdUser();
    int     getIdMember();
    QString getName();
    QString getIp();
    int     getIdConversation();
    void    setInfo(int idUser, int idMember, QString name, QString ip, int idConversation);
};

#endif // MEMBER_H
