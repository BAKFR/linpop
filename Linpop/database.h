#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QVariant>
#include <string>
#include <iostream>
#include <ostream>
#include "contact.h"
#include "user.h"
#include "conversation.h"
#include "member.h"

class Database
{
    QSqlDatabase    bdd;
    QString         bddname;
    QString         username;
    QString         pwd;
    int             id_user;

public:
    Database(QString &otherBddname);

    int                 openDatabase();
    int                 closeDatabase();

    User                *getUser(QString &nickname, QString &pwd);
    QList<Contact*>     getListContact(int &user);
    Contact             *getContact(int &idUser, QString &nickname, QString &ip);
    QList<Conversation> getListConv(int &idUser);
    Conversation        getConv(int &idUser, int &idConv);
    QList<Member>       getListMember(int &idConv);
    Member              getMember(int &idMember, int &idConv);
//    Log                 getLog(int &idConv);
    int                 updateLog(Conversation &conv);
    int                 addUser(User &user);
    int                 addContact(Contact &contact);
    int                 addMember(Member &member);
//    int                 addLog(Log &log);
    int                 addConv(Conversation &conv);
    int                 deleteContact(Contact &contact);
    int                 getUser(Contact &contact, QString &nickname);

    QString getBddName();
    QString getUserName();
    QString getPwd();
    int     getIdUser();

    void    setBddName(QString &other);
    void    setUserName(QString &other);
    void    setPwd(QString &other);
    void    setIdUser(int &other);
};

#endif // DATABASE_H
