#ifndef USER_H
#define USER_H

#include <QMainWindow>

class User
{
    int     _idUser;
    QString _userName;
    QString _password;

public:
    User();
    User(int idUser, QString userName, QString password);
    ~User();

public:
    int     getIdUser();
    QString getUserName();
    QString getPassword();
    void    setInfo(int idUser, QString userName, QString password);
};

#endif // USER_H
