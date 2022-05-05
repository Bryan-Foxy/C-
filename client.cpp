#include "client.h"
#include <QDebug>
client::client()
{
id=0;
nom="";
prenom="";
age=0;
adresse="";
}
client::client(int id,QString nom,QString prenom, QString adresse,int age)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
  this->adresse=adresse;
}
QString client::get_nom(){return  nom;}
QString client::get_prenom(){return prenom;}
QString client::get_adresse(){return adresse;}
int client::get_id(){return  id;}
int client::get_age(){return  age;}

bool client::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO client (ID, NOM, PRENOM, ADRESSE, AGE) "
                    "VALUES (:id, :nom, :prenom, :adresse, :age)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":age", age);

return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client ORDER BY Nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    return model;
}

QSqlQueryModel * client::afficher2(QString val)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client where ID= '"+val+"'or NOM='"+val+"'or PRENOM='"+val+"' ORDER BY Nom" );

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    return model;
}

bool client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from client where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool client::modifier(int id,QString nom,QString prenom,QString adresse,int age)
{
  QSqlQuery query;
  QString res= QString::number(id);
query.prepare("update client set  Nom= :nom, Prenom= :prenom , adresse= :adresse, age= :age where ID= :id") ;
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":age", age);
return    query.exec();
}
QSqlQueryModel * client :: rechercher(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from client where ID like '"+ch+"%'";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("ADRESSE"));

    return model;
}
