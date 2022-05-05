#ifndef CLIENT_H
#define CLIENT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class client
{public:
    client();
    client(int,QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    int get_id();
    int get_age();
    bool ajouter();
    bool modifier(int,QString,QString,QString,int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2(QString);
    QSqlQueryModel * rechercher(const QString);

    bool supprimer(int);
    void chercher();
private:
    QString nom,prenom,adresse;
    int id,age;

};

#endif // CLIENT_H
