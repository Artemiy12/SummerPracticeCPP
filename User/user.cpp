#include "user.h"
#include "message.h"
#include <QVector>

User::User()
{

}

User::User(const QString login, const QString password)
{
    this->login = login;
    this->password = password;
}

User::User(const QString login, const QString password, const QVector<Message> messages)
{
    this->login = login;
    this->password = password;
    this->messages = messages;
}

QVector<Message> User::getMessages()
{
    return messages;
}

void User::addMessage(const Message &message)
{
    this->messages.push_back(message);
}

bool User::verification(const QVector<User> &users, const QString login, const QString password)
{
    for (int i = 0; i < users.size(); i++)
    {
        User user = users[i];
        if(user.login == login && user.password == password)
        {
            return true;
        }
    }
    return false;
}


