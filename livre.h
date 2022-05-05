#ifndef LIVRE_H
#define LIVRE_H
#include"QString"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
class livre
{
    int ID;
    QString langue;

public:
    livre();
  bool  ajouter();
    livre(int,QString);
    QSqlQueryModel * afficher();
    void  supprimer(QString ID);
    bool modifier(int,QString);
    QSqlQueryModel * rechercher(const QString);

};

#endif // LIVRE_H
