#include "connexion.h"

Connection::Connection()
{

}
bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("mybase");
    db.setUserName("system");
    db.setPassword("SYSTEM");

    if (db.open())
        test=true;


    return test;
}
