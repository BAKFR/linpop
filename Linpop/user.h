#ifndef USER_H
#define USER_H

#include <QMainWindow>

class User
{
    QString _userName;
    QString _password;

public:
    User();
    User(QString userName, QString password);
    ~User();

public:
    QString getUserName();
    QString getPassword();
    void    setUserName(QString &other);
    void    setPassword(QString &other);
    void    setInfo(QString &userName, QString &password);

};

#endif // USER_H
