#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>

class Database
{
    QSqlDatabase    bdd;
    QString         bddname;
    QString         username;
    QString         pwd;
    int             id_user;

public:
    Database(QString otherBddname, QString otherUsername,
             QString otherPwd, int otherId_user);

    int                 openDatabase();
    int                 closeDatabase();
/*
    int                 getUser(QString &nickname, QString &pwd);
    QList<Contact>      getListContact(int &user);
    Contact             getContact(int &idUser, int &idContact);
    QList<Conversation> getListConv(int &idUser);
    Conversation        getConv(int &idUser, int &idConv);
    QList<Member>       getListMember(int &idConv);
    Member              getMember(int &idMember, int &idConv);
    Log                 getLog(int &idConv);
    int                 updateLog(Conversation &conv);
    int                 addUser(User &user);
    int                 addContact(Contact &contact);
    int                 addMember(Member &member);
    int                 addLog(Log &log);
    int                 addConv(Conversation &conv);
    int                 deleteContact(Contact &contact);
    int                 getUser(Contact &contact, QString &nickname);
*/

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
