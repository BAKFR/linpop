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

QList<Contact*>      *Database::getListContact(int &user)
{
    QList<Contact*>  *contactList = NULL;
    QString         statement;
    QSqlQuery       query;

    contactList = new QList<Contact*>();
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
            *contactList << newContact;

        }
    }
    else
        return (NULL);

    return (contactList);
}

Contact             Database::getContact(int &idUser, int &idContact)
{
    Contact         contact = Contact();

    return (contact);
}

QList<Conversation> Database::getListConv(int &idUser)
{
    QList<Conversation>    convList = QList<Conversation>();

    return (convList);
}

Conversation        Database::getConv(int &idUser, int &idConv)
{
    Conversation    conv = Conversation();

    return (conv);
}

QList<Member>       Database::getListMember(int &idConv)
{
    QList<Member>   listMember = QList<Member>();

    return (listMember);
}

Member              Database::getMember(int &idMember, int &idConv)
{
    Member          member = Member();

    return (member);
}

/*Log                 Database::getLog(int &idConv)
{
    return (NULL);
}*/

int                 Database::updateLog(Conversation &conv)
{
    return (0);
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

/*int                 Database::addLog(Log &log)
{
    return (0);
}*/

int                 Database::addConv(Conversation &conv)
{
    return (0);
}

int                 Database::deleteContact(Contact &contact)
{
    return (0);
}

int                 Database::getUser(Contact &contact, QString &nickname)
{
    return (0);
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
