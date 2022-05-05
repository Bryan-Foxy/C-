#include "agent.h"
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

agent::agent()
{
    CIN=0;
    nom="";
    prenom="";
    mail="";
    role="";
}


agent::agent(int CIN,QString nom,QString prenom,QString mail, QString role)
{
  this->CIN=CIN;
  this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->role=role;
}
    QString agent::get_nom(){return  nom;}
    QString agent::get_prenom(){return prenom;}
    QString agent::get_mail(){return mail;}
    QString agent::get_role() {return role;}
    int agent ::get_CIN(){return  CIN;}


bool agent::ajouter()
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("INSERT INTO AGENT (CIN, NOM, PRENOM, MAIL, ROLE) "
                    "VALUES (:CIN, :nom, :prenom,:mail, :role)");
query.bindValue(":CIN", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":mail", mail);
query.bindValue(":role", role);

return    query.exec();
}

QSqlQueryModel * agent::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from AGENT ORDER BY CIN");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Role"));
    return model;

}

bool agent::supprimer(int CIN)
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from AGENT where CIN= :CIN");
query.bindValue(":CIN", res);
return    query.exec();
}

bool agent::modifier(int CIN,QString nom, QString prenom,QString role,QString mail)
{


     QSqlQuery query;
    QString res= QString::number(CIN);
    query.prepare("UPDATE AGENT SET NOM=:nom ,PRENOM=:prenom,MAIL=:mail,ROLE=:role where CIN=:CIN");
    query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":role", role);
     return    query.exec();
}
QSqlQueryModel * agent :: rechercher(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from AGENT where CIN like '"+ch+"%'";
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Role"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Mail"));
    return model;
}
QChartView * agent ::statistique(){
    agent a1(CIN,"nom","prenom","mail","role");
    agent a2(CIN,"nom","prenom","role","mail");
    agent a3(CIN,"nom","prenom","role","mail");
    agent a4(CIN,"nom","prenom","role","mail");
    agent a5(CIN,"nom","prenom","role","mail");
    agent a6(CIN,"nom","prenom","role","mail");
    //![1]
        QBarSet *set0 = new QBarSet(a1.get_nom() +" "+ a1.get_prenom());
        QBarSet *set1 = new QBarSet(a2.get_nom() +" "+ a2.get_prenom());
        QBarSet *set2 = new QBarSet(a3.get_nom() +" "+ a3.get_prenom());
        QBarSet *set3 = new QBarSet(a4.get_nom() +" "+ a4.get_prenom());
        QBarSet *set4 = new QBarSet(a5.get_nom() +" "+ a5.get_prenom());

        *set0 << 1 << 2 << 3 << 4 << 5 << 6 << 3 << 4 << 5 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7 << 5 << 0 << 0 << 4 << 0 << 7 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5 << 3 << 5 << 8 << 13 << 8 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2  << 5 << 6 << 7 << 3 << 4 << 5 ;
    //![1]

    //![2]
        QStackedBarSeries *series = new QStackedBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistique");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sep"
                   << "Oct" << "Nov" << "Dec";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]
        return chartView;
}
