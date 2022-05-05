#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QChartView>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
QT_CHARTS_USE_NAMESPACE

class agent
{
public:
    agent();
    agent(int,QString,QString,QString,QString);
    QString get_nom();
    QString get_mail();
    QString get_role();
    QString get_prenom();
    int get_CIN();

    void set_nom(QString nom);
    void set_mail(QString mail);
    void set_role(QString role);
    void set_prenom(QString prenom);
    void set_CIN(int cin);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString);
    QSqlQueryModel * rechercher(const QString);
    QChartView * statistique();

private:
    QString nom,prenom, role , mail;
    int CIN;


};

#endif // AGENT_H
