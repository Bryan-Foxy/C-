#include "user.h"

user::user()
{

}

user::user(QString username,QString password)
{
    this->id = 0;
    this->username = username;
    this->password = password;
}

user::user(int id,QString username,QString password)
{
    this->id = id;
    this->username = username;
    this->password = password;
}

int user::login()
{

    QSqlQuery query;

    query.prepare("select * from profil where login = :username and mdp= :password");
    query.bindValue(":username",this->username);
    query.bindValue(":password",this->password);

    query.exec();

    int count_user = 0;
    while (query.next()) {
        count_user++;
    }

    if (count_user == 1) {
        return 0;
    }
    else if (count_user > 1 ) {
        return 1;
    }
    else{
        return 2;
    }
}
bool user::passwordcheck()
{
    QSqlQuery query;
    query.prepare("select * from users where mdp= :password");
    query.bindValue(":password",password);
    query.exec();
    if(query.next())

        return true;

    else
        return false;
}
