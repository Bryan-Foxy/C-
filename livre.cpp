#include "livre.h"

livre::livre()
{
    ID=0;
    langue="";

}
livre::livre(int ID,QString langue)
{
    this->ID=ID;
    this->langue=langue;
}

bool livre :: ajouter()
{
    QSqlQuery query;
    QString res1=QString::number(ID);
printf("test");
         query.prepare("INSERT INTO livre(ID,LANGUE) "
                       "VALUES (:ID,:langue)");
         query.bindValue(":ID",res1);
         query.bindValue(":langue", langue);
         return query.exec();
}

QSqlQueryModel * livre :: afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from livre order by ID");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Mot de Passe"));
    return model;
}


void livre :: supprimer(QString ID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM livre WHERE ID=:ID");
    query.bindValue(":ID",ID);
    query.exec();

}


bool livre :: modifier(int ID, QString langue)
{
    QSqlQuery query;
    QString res1=QString::number(ID);

    query.prepare("UPDATE livre SET LANGUE=:modiflangue ,WHERE ID =:modifID;");
         query.bindValue(":modifID",ID);
       query.bindValue(":modiflangue",langue);
          /* query.bindValue(":modifID",res1);
         query.bindValue(":modifnbr_pages",res2);
         query.bindValue(":modifprix",res3);*/
         return query.exec();
}
QSqlQueryModel * livre :: rechercher(QString strr)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="Select * from livre where ID like '"+strr+"%'";
    model->setQuery(str);

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Mot de Passe"));
    return model;
}

