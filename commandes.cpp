#include "commandes.h"
#include <QString>


commandes::commandes()
{
    idclient=0 ;
    nom_c="";
    adresse="" ;
    prix =0.0;
    datedelivraison="";

}
commandes::commandes(int idclient ,QString nom_c,QString datedelivraison,QString adresse,double prix)
{
    this->idclient=idclient;
    this->nom_c=nom_c;
    this->datedelivraison=datedelivraison ;
    this->adresse=adresse ;
    this->prix=prix ;


}

int commandes::get_idclient(){return idclient;}
QString commandes::get_nom_c(){return  nom_c;}
QString commandes::get_datedelivraison(){return  datedelivraison;}

QString commandes::get_adresse(){return adresse ;}


bool commandes::ajouter()
{
QSqlQuery query;
QString res= QString::number(idclient);
QString res1= QString::number(prix);


query.prepare("INSERT INTO COMMANDES (IDCLIENT,NOMCLIENT,ADRESSE,DATEDELIVRAISON,PRIX) "
                    "VALUES (:idclient, :nom_c, :adresse, :datedelivraison, :prix)");
query.bindValue(":idclient", idclient);
query.bindValue(":nom_c",nom_c);
query.bindValue(":adresse", adresse);
query.bindValue(":datedelivraison", datedelivraison);
query.bindValue(":prix", prix);

return    query.exec();
}
QSqlQueryModel * commandes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from COMMANDES ORDER BY IDCLIENT ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM CLIENT "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE DE LIVRAISON"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
    return model;
}
bool commandes::supprimer(int idclient)
{
QSqlQuery query;
QString res= QString::number(idclient);
query.prepare("Delete from COMMANDES where IDCLIENT = :idclient ");
query.bindValue(":idclient", res);
return    query.exec();
}
bool commandes::modifier(int idclient,QString nom_c,QString adresse,QString datedelivraison,double prix)
{
    QSqlQuery query ;
    QString res2=QString::number(idclient) ;
    QString res1= QString::number(prix);
    query.prepare("update COMMANDES set NOM_C=:nom_c,ADRESSE=:adresse,DATEDELIVRAISON=:datedelivraison,PRIX=:prix where IDCLIENT= :idclient ");
    query.bindValue(":idclient", res2);
    query.bindValue(":nom_c",nom_c );
    query.bindValue(":adresse", adresse);
    query.bindValue(":datedelivraison", datedelivraison);
    query.bindValue(":prix", res1);
    return  query.exec();
}

QSqlQueryModel * commandes :: rechercher(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from COMMANDES where IDCLIENT like '"+ch+"%'";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATE DE LIVRAISON"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("PRIX"));

    return model;
}
