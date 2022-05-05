#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
};

#endif // CONNEXION_H
