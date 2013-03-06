#ifndef USER_H
#define USER_H

#include <QMainWindow>

class User
{
    QString _userName;
    QString _password;
    int     _idUser;

public:
    User();
    User(QString userName, QString password);
    ~User();

public:
    QString getUserName();
    QString getPassword();
    int     getIdUser();
    void    setUserName(QString &other);
    void    setPassword(QString &other);
    void    setIdUser(int &other);
    void    setInfo(QString &userName, QString &password);

};

#endif // USER_H
