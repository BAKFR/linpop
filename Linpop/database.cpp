#include "database.h"

Database::Database(QString otherBddname, QString otherUsername,
                   QString otherPwd, int otherId_user)
{
    this->bddname = otherBddname;
    this->pwd = otherPwd;
    this->username = otherUsername;
    this->id_user = otherId_user;
}

int         Database::openDatabase()
{
    int     error = 1;

    this->bdd = QSqlDatabase::addDatabase("QSQLITE");
//    this->bdd.setDatabaseName(this->bddname);
    this->bdd.setDatabaseName("TESTINUTILE.bd");

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

User                 Database::getUser(QString &nickname, QString &pwd)
{
    User            user = User();

    return (user);
}

QList<Contact>      Database::getListContact(int &user)
{
    QList<Contact>  contactList = QList<Contact>();

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
    std::string     statement;
    int             error = 1;

    statement = "INSERT INTO User (Id, Username, Password) VALUES(";
    statement += QString::number(user.getIdUser()).toStdString() + ", " + user.getUserName().toStdString();
    statement += ", " + user.getPassword().toStdString() + ");";

/*    query.prepare("INSERT INTO User (Id, Username, Password)"
                  "VALUES (:id, :username, :password)");
    query.bindValue(":id", user.getIdUser());
    query.bindValue(":username", user.getUserName());
    query.bindValue(":password", user.getPassword());
*/
    QMapIterator<QString, QVariant> i(query.boundValues());
       while (i.hasNext()) {
           i.next();
           std::cout << i.key().toUtf8().data() << ": "
                << i.value().toString().toUtf8().data() << std::endl;
       }

    std::cout << statement << std::endl;

    if (query.exec(QString(statement.c_str())) == true)
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
    return (0);
}

int                 Database::addMember(Member &member)
{
    return (0);
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
