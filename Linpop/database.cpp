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
    this->bdd.setDatabaseName(this->bddname);

    if (this->bdd.open())
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
