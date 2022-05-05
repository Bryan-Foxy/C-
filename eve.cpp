#include "eve.h"


eve::eve()
{
Id=0;
Titre="";
Date="";
Adresse="";
}
eve::eve(int Id,QString Titre,QString Date,QString Adresse)
{
    this->Id=Id;
  this->Titre=Titre;
  this->Date=Date;
  this->Adresse=Adresse;
}


bool eve::ajouter()
{
QSqlQuery query;
QString res= QString::number(Id);
query.prepare("INSERT INTO EVE (ID, TITRE, EDATE, ADRESSE) "
                    "VALUES (:Id, :Titre, :Date, :Adresse)");
query.bindValue(":Id", res);
query.bindValue(":Titre", Titre);
query.bindValue(":Date", Date);
query.bindValue(":Adresse", Adresse);

return    query.exec();
}

QSqlQueryModel * eve::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EVE ORDER BY ID");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    return model;
}


bool eve::supprimer(int Id)
{
QSqlQuery query;
QString res= QString::number(Id);
query.prepare("Delete from EVE where ID = :Id ");
query.bindValue(":Id", res);
return    query.exec();
}

bool eve::modifier(int Id,QString Titre,QString Date,QString Adresse)
{
    QSqlQuery query;
    QString res= QString::number(Id);
    query.prepare("UPDATE EVE SET TITRE=:Titre,  EDATE=:Date, ADRESSE=:Adresse WHERE ID =:Id ");
    query.bindValue(":Id", res);
    query.bindValue(":Titre", Titre);
    query.bindValue(":Date", Date);
    query.bindValue(":Adresse", Adresse);

    return    query.exec();

}
QSqlQueryModel * eve :: rechercher(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from EVE where ID like '"+ch+"%'";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("TITRE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE"));

    return model;
}



