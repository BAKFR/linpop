#include "database.h"

Database::Database(QString &otherBddname)
{
    this->bddname = otherBddname;
    this->pwd = "";
    this->username = "";
    this->id_user = 0;
}

int         Database::openDatabase()
{
    int     error = 1;

    this->bdd = QSqlDatabase::addDatabase("QSQLITE");
    this->bdd.setDatabaseName(this->bddname);

    if (this->bdd.open() == true)
    {
        std::cout << "Database connection successed" << std::endl;
        error = 0;
    }
    else
    {
        std::cout << "Database connection failed" << std::endl;
        error = -1;
    }
    return (error);
}

int         Database::closeDatabase()
{
    int     error = 1;

    if (this->bdd.isOpen())
    {
        this->bdd.close();
        std::cout << "Database closed"<< std::endl;
        error = 0;
    }
    else
    {
        std::cout << "Database already closed !"<< std::endl;
        error = -1;
    }
    return (error);
}

User                 *Database::getUser(QString &nickname, QString &pwd)
{
    User            *user = NULL;
    QSqlQuery       query;
    QString         statement;

    user = new User();
    statement = "SELECT * FROM User WHERE(Username = '";
    statement += nickname + "' AND Password = '";
    statement += pwd + "');";

    if (query.exec(statement))
    {
        int fieldIdUser = query.record().indexOf("Id");
        int fieldUserName = query.record().indexOf("Username");
        int fieldPassword = query.record().indexOf("Password");

        if (query.next())
        {
            int idUser = query.value(fieldIdUser).toInt();
            QString userName = query.value(fieldUserName).toString();
            QString password = query.value(fieldPassword).toString();
            user->setIdUser(idUser);
            user->setUserName(userName);
            user->setPassword(password);
        }
        else
            return (NULL);
    }
    else
        return (NULL);

    return (user);
}

QList<Contact*>      Database::getListContact(int &user)
{
    QList<Contact*> contactList;
    QString         statement;
    QSqlQuery       query;

    contactList = QList<Contact*>();
    statement = "SELECT * FROM Contact";
    statement += " WHERE (Id_User = " + QString::number(user) + ");";

    if (query.exec(statement))
    {
        int fieldIdUser = query.record().indexOf("Id_User");
        int fieldIdContact = query.record().indexOf("Id");
        int fieldContactName = query.record().indexOf("Pseudo");
        int fieldIp = query.record().indexOf("Ip");

        while (query.next())
        {
            int idUser = query.value(fieldIdUser).toInt();
            int idContact = query.value(fieldIdContact).toInt();
            QString contactName = query.value(fieldContactName).toString();
            QString ip = query.value(fieldIp).toString();
            Contact*    newContact = new Contact();
            newContact->setIdContact(idContact);
            newContact->setIdUser(idUser);
            newContact->setContactName(contactName);
            newContact->setIp(ip);
            contactList << newContact;

        }
    }

    return (contactList);
}

Contact             *Database::getContact(int &idUser, QString &nickname, QString &ip)
{
    Contact         *contact = NULL;
    QSqlQuery       query;
    QString         statement;

    contact = new Contact();
    statement = "SELECT * FROM Contact WHERE(Pseudo = '";
    statement += nickname + "' AND IP = '";
    statement += ip + "' AND Id_User = " + QString::number(idUser) + ");";

    if (query.exec(statement))
    {
        int fieldIdUser = query.record().indexOf("Id_User");
        int fieldPseudo = query.record().indexOf("Pseudo");
        int fieldIp = query.record().indexOf("IP");

        while (query.next())
        {
            int idUser = query.value(fieldIdUser).toInt();
            QString Pseudo = query.value(fieldPseudo).toString();
            QString Ip = query.value(fieldIp).toString();
            contact->setContactName(Pseudo);
            contact->setIdUser(idUser);
            contact->setIp(Ip);
            return contact;
        }
    }
    return (NULL);
}

int                 Database::addUser(User &user)
{
    QSqlQuery       query;
    QString         statement;
    int             error = 1;

    statement = "INSERT INTO User (Username, Password) VALUES(";
        statement += "'" + user.getUserName();
        statement += "', '" + user.getPassword() + "');";

    if (query.exec(statement) == true)
    {
        std::cout << "Query [Add user] - Success" << std::endl;
        error = 0;
    }
    else
    {
        std::cout << "Query [Add user] - Fail" << std::endl;
        std::cout << "Error : " << query.lastError().text().toStdString() << std::endl;
        std::cout << "Query : " << query.lastQuery().toStdString() << std::endl;
        error = -1;
    }

    return (error);
}

int                 Database::addContact(Contact &contact)
{
    QSqlQuery       query;
    QString         statement;
    int             error = 1;

    statement = "INSERT INTO Contact (Id_User, Pseudo, IP) VALUES (";
    statement += QString::number(contact.getIdUser());
    statement += ", '" + contact.getContactName();
    statement += "', '" + contact.getIp() + "');";

    if (query.exec(statement) == true)
    {
        std::cout << "Query [Add contact] - Success" << std::endl;
        error = 0;
    }
    else
    {
        std::cout << "Query [Add contact] - Fail" << std::endl;
        std::cout << "Error : " << query.lastError().text().toStdString() << std::endl;
        std::cout << "Query : " << query.lastQuery().toStdString() << std::endl;
        error = -1;
    }

    return (error);
}

int                 Database::addMember(Member &member)
{
    QSqlQuery       query;
    QString         statement;
    int             error = 1;

    statement = "INSERT INTO Member (Id_User, Id_Conversation, Name, IP) VALUES (";
    statement += QString::number(member.getIdUser());
    statement += ", " + QString::number(member.getIdConversation());
    statement += ", '" + member.getName();
    statement += "', '" + member.getIp() + "');";

    if (query.exec(statement) == true)
    {
        std::cout << "Query [Add member] - Success" << std::endl;
        error = 0;
    }
    else
    {
        std::cout << "Query [Add member] - Fail" << std::endl;
        std::cout << "Error : " << query.lastError().text().toStdString() << std::endl;
        std::cout << "Query : " << query.lastQuery().toStdString() << std::endl;
        error = -1;
    }
    return (error);
}

QList<QString>      Database::getHistory()
{
    QList<QString>  logs;
    QString         statement;
    QSqlQuery       query;

    logs.clear();
    statement = "SELECT Line FROM Logs ORDER BY Id_Conv ASC, Id ASC;";

    if (query.exec(statement))
    {
        int fieldConv = query.record().indexOf("Line");

        while (query.next())
        {
            QString log = query.value(fieldConv).toString();
            logs << log;

        }
    }

    return (logs);
}

int                Database::setHistory(int idConv, QString line)
{
    QSqlQuery       query;
    QString         statement;
    int             error = 1;

    statement = "INSERT INTO Logs (Id_Conv, Line) VALUES (";
    statement += QString::number(idConv);
    statement += ", '" + line + "');";

    if (query.exec(statement) == true)
    {
        std::cout << "Query [Add Log] - Success" << std::endl;
        error = 0;
    }
    else
    {
        std::cout << "Query [Add Log] - Fail" << std::endl;
        std::cout << "Error : " << query.lastError().text().toStdString() << std::endl;
        std::cout << "Query : " << query.lastQuery().toStdString() << std::endl;
        error = -1;
    }

    return (error);
}

QString     Database::getBddName()
{
    return (this->bddname);
}

QString     Database::getUserName()
{
    return (this->username);
}

QString     Database::getPwd()
{
    return (this->pwd);
}

int         Database::getIdUser()
{
    return (this->id_user);
}

void        Database::setBddName(QString &other)
{
    this->bddname = other;
}

void        Database::setUserName(QString &other)
{
    this->username = other;
}

void        Database::setPwd(QString &other)
{
    this->pwd = other;
}

void        Database::setIdUser(int &other)
{
    this->id_user = other;
}
