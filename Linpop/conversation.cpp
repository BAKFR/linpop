#include "conversation.h"

Conversation::Conversation()
{
}

Conversation::Conversation(int idConversation, int idUser, QString content, QDate date):
    _idConversation(idConversation),
    _idUser(idUser),
    _content(content),
    _date(date)
{

}

Conversation::~Conversation()
{

}

int             Conversation::getidConversation()
{
    return(this->_idConversation);
}

int             Conversation::getIdUser()
{
    return(this->_idUser);
}

QString         Conversation::getContent()
{
    return(this->_content);
}


QDate           Conversation::getDate()
{
    return(this->_date);
}

void            Conversation::setInfo(int idConversation, int idUser, QString content, QDate date)
{
    this->_idConversation = idConversation;
    this->_idUser = idUser;
    this->_content = content;
    this->_date = date;
}
