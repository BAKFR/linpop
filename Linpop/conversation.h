#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <QMainWindow>
#include <QDate>
#include "member.h"

class Conversation
{
    int             _idConversation;
    int             _idUser;
    QString         _content;
    //QList<Member>   _members;
    QDate           _date;

public:
    Conversation();
    Conversation(int idConversation, int idUser, QString content, QDate date);
    ~Conversation();

public:
    int             getidConversation();
    int             getIdUser();
    QString         getContent();
    QDate           getDate();
    void            setInfo(int idConversation, int idUser, QString content, QDate date);

};

#endif // CONVERSATION_H
