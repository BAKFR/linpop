#ifndef CONTACT_H
#define CONTACT_H

#include <QMainWindow>

class Contact
{
    int     _idUser;
    int     _idContact;
    QString _contactName;
    QString _ip;

public:
    Contact();
    ~Contact();

public:
    int     getIdContact();
    int     getIdUser();
    QString getContactName();
    QString getIp();
    void    setIdUser(int &idUser);
    void    setIdContact(int &idContact);
    void    setContactName(QString &contactName);
    void    setIp(QString &ip);
    void    setInfo(int idUser, int idContact, QString contactName, QString ip);

};

#endif // CONTACT_H
