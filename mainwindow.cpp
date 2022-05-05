#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>

#include <QtCharts/QChartView>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     livre l;
    ui->setupUi(this);
    QPixmap bg(":/img/bg1.png");
    ui->label->setPixmap(bg);
this->setWindowTitle("FIT-HUB");
   // QCursor cursorTarget = QCursor(QPixmap(":/img/bg1.png"));
        //ui->graphicsView->setCursor(cursorTarget); // Set the cursor target
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_events_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(4);
     this->ui->tabevenement->setModel(tmpevenement.afficher());

}

void MainWindow::on_livres_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->afficher->setModel(tmplivre.afficher());
}

void MainWindow::on_retour_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
   this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Sretour_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
  this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Mretour_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ajouter_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int id=ui->id_ajout->text().toInt();
    livre l(id,this->ui->langue_ajout->text());
   l.ajouter();
    this->ui->stackedWidget->setCurrentIndex(0);
      ui->afficher->setModel(tmplivre.afficher());
      MainWindow::notif("Livre","Ajout d'un livre est reussite");
}

void MainWindow::on_supprimer_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_modifier_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_ModifierID_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQuery qry;
    QString Id=ui->lineEdit_ID->text();
    qry.prepare("select * from livre where ID='"+Id+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_MID->setText(qry.value(0).toString());
            ui->lineEdit_Mlivre->setText(qry.value(1).toString());
            //ui->lineEdit_9->setText(qry.value(2).toString());
            /*ui->lineEdit_MnbrPage->setText(qry.value(3).toString());
            ui->lineEdit_Mlangue->setText(qry.value(4).toString());
            ui->lineEdit_Mprix->setText(qry.value(5).toString());*/

        }
    }
    this->ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_SupprimerID_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QString id=ui->lineEdit_ID->text();
        livre l;
        l.supprimer(id);
        this->ui->stackedWidget->setCurrentIndex(0);
         ui->afficher->setModel(tmplivre.afficher());
         MainWindow::notif("Profil","Suppresion d'un Profil est reussite");

}

void MainWindow::on_Mvalider_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int id=ui->lineEdit_MID->text().toInt();

 //l.modifier(id,this->ui->lineEdit_Mlangue->text() );

     this->ui->stackedWidget->setCurrentIndex(0);
   ui->afficher->setModel(tmplivre.afficher());
   MainWindow::notif("Profil","Modification d'un Profil est reussite");

}

void MainWindow::on_rechercher_textChanged(const QString &arg1)
{
    if (arg1=="")
    ui->afficher->setModel(l.afficher());
    else
     this->ui->afficher->setModel(l.rechercher(arg1));
}


void MainWindow::on_rechercher_2_textChanged(const QString &arg1)
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    if (arg1=="")
    ui->tabevenement->setModel(e.afficher());
    else
    this->ui->tabevenement->setModel(e.rechercher(arg1));
}

void MainWindow::on_ajouter_2_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_supprimer_2_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
   this->ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_modifier_2_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_retour_2_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pb_ajouter_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int Id=ui->lineEdit_id_eve->text().toInt();
    QString Nom = ui->lineEdit_titre_eve->text();
    QString Date= ui->lineEdit_date_eve->text();
    QString Prix= ui->lineEdit_adresse_eve->text();
  eve e(Id,Nom,Date,Prix);
  e.ajouter();
   ui->tabevenement->setModel(tmpevenement.afficher());
  this->ui->stackedWidget->setCurrentIndex(4);
   MainWindow::notif("Evenement ","Ajout d'un Evenement reussite");
}

void MainWindow::on_ModifierID_2_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQuery qry;
    QString Id=ui->lineEdit_id_d_eve->text();
    qry.prepare("select * from eve where ID='"+Id+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_Mid->setText(qry.value(0).toString());
            ui->lineEdit_Mtitre->setText(qry.value(1).toString());
            ui->lineEdit_Mdate->setDate(qry.value(2).toDate());
            ui->lineEdit_MAdresse->setText(qry.value(3).toString());

        }
    }
   this->ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_SupprimerID_2_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int Id = ui->lineEdit_id_d_eve->text().toInt();
    tmpevenement.supprimer(Id);
    ui->tabevenement->setModel(tmpevenement.afficher());//refresh
    this->ui->stackedWidget->setCurrentIndex(4);
    MainWindow::notif("Evenement ","Supprision d'un Evenement reussite");


}

void MainWindow::on_Sretour_2_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_3_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_4_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int Id = ui->lineEdit_Mid->text().toInt();
    QString Titre = ui->lineEdit_Mtitre->text();
    QString Date= ui->lineEdit_Mdate->text();
    QString Adresse= ui->lineEdit_MAdresse->text();
  tmpevenement.modifier(Id,Titre,Date,Adresse);
  ui->tabevenement->setModel(tmpevenement.afficher());
    this->ui->stackedWidget->setCurrentIndex(4);
  MainWindow::notif("Evenement ","Modiification d'un Evenement reussite");

}

void MainWindow::on_commandes_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
     ui->tabcommande->setModel(c.afficher());
  this->ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_ajouter_5_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_supprimer_5_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_ModifierID_7_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQuery qry;
    QString idclinet=ui->lineEdit_ID_client_com->text();
    qry.prepare("select * from COMMANDES where ID_CLIENT='"+idclinet+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_MID_client_com->setText(qry.value(0).toString());
            ui->lineEdit_Mnom_livre_com->setText(qry.value(1).toString());
            ui->lineEdit_MDDL_com->setDate(qry.value(2).toDate());
            ui->lineEdit_MAdre_com->setText(qry.value(3).toString());
            ui->lineEdit_Mprix_com->setText(qry.value(4).toString());

        }
    }
    this->ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_modifier_5_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_rechercher_5_textChanged(const QString &arg1)
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    if (arg1=="")
    ui->tabcommande->setModel(c.afficher());
    else
    this->ui->tabcommande->setModel(c.rechercher(arg1));
}

void MainWindow::on_retour_7_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_Sretour_5_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_Mretour_3_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
   this->ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_6_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int idclient=ui->id_client_aj_com->text().toInt();
    QString nomlivre = ui->Nom_livre_aj_com->text();
    QString datedelivraison= ui->date_livraison_aj_com->text();
    QString Adresse= ui->adresse_aj_com->text();
    double prix=ui->Prix_aj_com->text().toDouble();
  commandes c(idclient,nomlivre,datedelivraison,Adresse,prix);
  c.ajouter();
   ui->tabcommande->setModel(c.afficher());
    this->ui->stackedWidget->setCurrentIndex(8);
   MainWindow::notif("Commande","Ajout d'un commande est reussite");
}

void MainWindow::on_SupprimerID_5_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int id=ui->lineEdit_ID_client_com->text().toInt();
        commandes c;
        c.supprimer(id);
        this->ui->stackedWidget->setCurrentIndex(8);
         ui->tabcommande->setModel(c.afficher());
          MainWindow::notif("Commande","Supprision d'un commande est reussite");
}

void MainWindow::on_Mvalider_3_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int idclient=ui->lineEdit_MID_client_com->text().toInt();
    QString nomlivre = ui->lineEdit_Mnom_livre_com->text();
    QString datedelivraison= ui->lineEdit_MDDL_com->text();
    QString Adresse= ui->lineEdit_MAdre_com->text();
    double prix=ui->lineEdit_Mprix_com->text().toDouble();
  c.modifier(idclient,nomlivre,datedelivraison,Adresse,prix);
  ui->tabcommande->setModel(c.afficher());
    this->ui->stackedWidget->setCurrentIndex(8);
   MainWindow::notif("Commande","Modification d'un commande est reussite");
}

void MainWindow::on_ajouter_6_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
  this->ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_supprimer_6_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_modifier_6_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_agents_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(12);
    ui->tabagent->setModel(a.afficher());
}

void MainWindow::on_retour_8_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_7_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int CIN=ui->cin_agent_aj->text().toInt();
    QString nom = ui->nom_agent_aj->text();
    QString prenom= ui->prenom_agent_aj->text();
    QString role= ui->role_agent_aj->text();
    QString mail=ui->mail_agent_aj->text();
  agent a(CIN,nom,prenom,role,mail);
  a.ajouter();
   ui->tabagent->setModel(a.afficher());
   this->ui->stackedWidget->setCurrentIndex(12);
   MainWindow::notif("Agent","Ajout d'un agent est reussite");
}

void MainWindow::on_Sretour_6_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_ModifierID_9_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQuery qry;
    QString CIN=ui->lineEdit_cin_agent->text();
    qry.prepare("select * from agent where CIN='"+CIN+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->cin_agent_mod->setText(qry.value(0).toString());
            ui->nom_agent_mod->setText(qry.value(1).toString());
            ui->prenom_agent_mod->setText(qry.value(2).toString());
            ui->role_agent_mod->setText(qry.value(3).toString());
            ui->mail_agent_mod->setText(qry.value(4).toString());

        }
    }
    this->ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_SupprimerID_6_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int CIN=ui->lineEdit_cin_agent->text().toInt();
        agent a;
        a.supprimer(CIN);
         ui->tabagent->setModel(a.afficher());
    this->ui->stackedWidget->setCurrentIndex(12);
         MainWindow::notif("Agent","Supprision d'un agent est reussite");
}

void MainWindow::on_retour_9_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_8_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int CIN=ui->cin_agent_mod->text().toInt();
    QString nom = ui->nom_agent_mod->text();
    QString prenom= ui->prenom_agent_mod->text();
    QString role= ui->role_agent_mod->text();
    QString mail=ui->mail_agent_mod->text();
  a.modifier(CIN,nom,prenom,role,mail);
  ui->tabagent->setModel(a.afficher());
    this->ui->stackedWidget->setCurrentIndex(12);
  MainWindow::notif("Agent","Modification d'un agent est reussite");
}



void MainWindow::on_rechercher_6_textChanged(const QString &arg1)
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    if (arg1=="")
    ui->tabagent->setModel(a.afficher());
    else
    this->ui->tabagent->setModel(a.rechercher(arg1));
}



void MainWindow::on_ajouter_7_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
  this->ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_supprimer_7_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
  this->ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_modifier_7_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
  this->ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_retour_10_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_9_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int idstock=ui->id_stock_aj->text().toInt();
    QString categorie = ui->categorie_stock_aj->text();
    QString adresse= ui->adresse_stock->text();
  stock s(idstock,categorie,adresse);
  s.ajouter();
   ui->tabstock->setModel(s.afficher());
    this->ui->stackedWidget->setCurrentIndex(16);
   MainWindow::notif("Stock ","Ajout d'un stock est reussite");
}

void MainWindow::on_Sretour_7_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_ModifierID_10_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQuery qry;
    QString idstock=ui->lineEdit_ID_stock->text();
    qry.prepare("select * from stock where ID='"+idstock+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->id_stock_mod->setText(qry.value(0).toString());
            ui->categorie_stock_mod->setText(qry.value(1).toString());
            ui->adresse_stock_mod->setText(qry.value(2).toString());
        }
    }
    this->ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_SupprimerID_7_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int idstock=ui->lineEdit_ID_stock->text().toInt();
        stock s;
        s.supprimer(idstock);
         ui->tabstock->setModel(s.afficher());
    this->ui->stackedWidget->setCurrentIndex(16);
          MainWindow::notif("Stock ","Supprision d'un stock est reussite");
}

void MainWindow::on_retour_11_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_10_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int idstock=ui->id_stock_mod->text().toInt();
    QString categorie = ui->categorie_stock_mod->text();
    QString adresse= ui->adresse_stock_mod->text();
  s.modifier(idstock,adresse,categorie);
  ui->tabstock->setModel(s.afficher());
    this->ui->stackedWidget->setCurrentIndex(16);
   MainWindow::notif("Stock ","Modification d'un stock est reussite");
}

void MainWindow::on_stocks_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    ui->tabstock->setModel(s.afficher());
    this->ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_rechercher_7_textChanged(const QString &arg1)
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    if (arg1=="")
    ui->tabstock->setModel(s.afficher());
    else
     this->ui->tabstock->setModel(s.rechercher(arg1));
}

void MainWindow::on_ajouter_8_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
  this->ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_supprimer_8_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
 this->ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_modifier_8_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
   this->ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_retour_12_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_pushButton_11_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int id=ui->id_client_aj->text().toInt();
    QString nom = ui->nom_client_aj->text();
    QString prenom= ui->prenom_client_aj->text();
    int age=ui->age_client_aj->text().toInt();
    QString adresse= ui->adresse_client_aj->text();
  client cl(id,nom,prenom,adresse,age);
  cl.ajouter();
   ui->tabclient->setModel(cl.afficher());
    this->ui->stackedWidget->setCurrentIndex(20);
   MainWindow::notif("Client","Ajout d'un client est reussite");

}

void MainWindow::on_clients_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    ui->tabclient->setModel(cl.afficher());
    this->ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_Sretour_8_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_SupprimerID_8_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int id=ui->lineEdit_ID_client->text().toInt();
        client cl;
        cl.supprimer(id);
         ui->tabclient->setModel(cl.afficher());
    this->ui->stackedWidget->setCurrentIndex(20);
         MainWindow::notif("Client","Supprision d'un client est reussite");

}

void MainWindow::on_ModifierID_11_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQuery qry;
    QString id=ui->lineEdit_ID_client->text();
    qry.prepare("select * from client where ID='"+id+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->id_client_mod->setText(qry.value(0).toString());
            ui->nom_client_mod->setText(qry.value(1).toString());
            ui->prenom_client_mod->setText(qry.value(2).toString());
            ui->age_client_mod->setText(qry.value(3).toString());
            ui->adresse_client_mod->setText(qry.value(4).toString());

        }
    }
    this->ui->stackedWidget->setCurrentIndex(23);

}

void MainWindow::on_retour_13_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(20);

}

void MainWindow::on_pushButton_12_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    int id=ui->id_client_mod->text().toInt();
    QString nom = ui->nom_client_mod->text();
    QString prenom= ui->prenom_client_mod->text();
    int age= ui->age_client_mod->text().toInt();
    QString adresse=ui->adresse_client_mod->text();
  cl.modifier(id,nom,prenom,adresse,age);
  ui->tabclient->setModel(cl.afficher());
    this->ui->stackedWidget->setCurrentIndex(20);
  MainWindow::notif("Client","Modification d'un client est reussite");

}

void MainWindow::on_rechercher_8_textChanged(const QString &arg1)
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    if (arg1=="")
    ui->tabclient->setModel(cl.afficher());
    else
    this->ui->tabclient->setModel(cl.rechercher(arg1));
}

void MainWindow::notif(QString t,QString m)
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QPixmap p(32,32);
    p.load("C:/Users/user16/Desktop/notification.png");
    QIcon icon(p);
    QSystemTrayIcon n(icon);
    n.setVisible(true);
    n.showMessage(t,m,QSystemTrayIcon::Information,1000);

}



void MainWindow::on_Excel_livre_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQueryModel  *model = new QSqlQueryModel() ;

    QString linki = QFileDialog::getSaveFileName(this, tr("Export TXT"),"/livre.txt", tr("Comma Separated Values (*.txt)"));


    li=new (livre);

        int x = 0;

        QString exportdata;

        model=li->afficher();

        int counthidden = 0, jint = 0;

        while (jint < model->columnCount()) {

        counthidden+=ui->tabevenement->isColumnHidden(jint);

        jint++;
        }


        while (x < model->columnCount())
        {

        if (!ui->afficher->isColumnHidden(x))
        {

        exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());

        //msgbox(exportdata);

        if (model->columnCount() - x != counthidden)

        exportdata.append(";");

        else

        exportdata.append("\n");

        }
        x++;

        }

        int z = 0;

        exportdata.append("\n");

        while (z < model->rowCount()) {

        x = 0;

        while (x < model->columnCount()) {

        if (!ui->afficher->isColumnHidden(x)) {


        exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


        if (model->columnCount() - x != counthidden)
        {
            exportdata.append(";");

        }
        else
        {
        exportdata.append("\n");

        }
        }

        x++;

        }
        exportdata.append("\n");

        z++;
        }



           QFile file;

           if (!linki.isEmpty()) {

         file.setFileName(linki);

                if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

                    return;
        }
        QByteArray ttext;

        ttext.append(exportdata);

        file.write(ttext);

        /* closing the file */
}

void MainWindow::on_fichiertxt_eve_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQueryModel  *model = new QSqlQueryModel() ;

    QString linki = QFileDialog::getSaveFileName(this, tr("Export TXT"),"/evenement.txt", tr("Comma Separated Values (*.txt)"));


    com=new (commandes);

        int x = 0;

        QString exportdata;

        model=com->afficher();

        int counthidden = 0, jint = 0;

        while (jint < model->columnCount()) {

        counthidden+=ui->tabcommande->isColumnHidden(jint);

        jint++;
        }


        while (x < model->columnCount())
        {

        if (!ui->tabcommande->isColumnHidden(x))
        {

        exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());

        //msgbox(exportdata);

        if (model->columnCount() - x != counthidden)

        exportdata.append(";");

        else

        exportdata.append("\n");

        }
        x++;

        }

        int z = 0;

        exportdata.append("\n");

        while (z < model->rowCount()) {

        x = 0;

        while (x < model->columnCount()) {

        if (!ui->afficher->isColumnHidden(x)) {


        exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


        if (model->columnCount() - x != counthidden)
        {
            exportdata.append(";");

        }
        else
        {
        exportdata.append("\n");

        }
        }

        x++;

        }
        exportdata.append("\n");

        z++;
        }



           QFile file;

           if (!linki.isEmpty()) {

         file.setFileName(linki);

                if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

                    return;
        }
        QByteArray ttext;

        ttext.append(exportdata);

        file.write(ttext);
}

void MainWindow::on_pushButton_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQueryModel  *model = new QSqlQueryModel() ;

    QString linki = QFileDialog::getSaveFileName(this, tr("Export TXT"),"/commandes.txt", tr("Comma Separated Values (*.txt)"));


    ev=new (eve);

        int x = 0;

        QString exportdata;

        model=ev->afficher();

        int counthidden = 0, jint = 0;

        while (jint < model->columnCount()) {

        counthidden+=ui->afficher->isColumnHidden(jint);

        jint++;
        }


        while (x < model->columnCount())
        {

        if (!ui->afficher->isColumnHidden(x))
        {

        exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());

        //msgbox(exportdata);

        if (model->columnCount() - x != counthidden)

        exportdata.append(";");

        else

        exportdata.append("\n");

        }
        x++;

        }

        int z = 0;

        exportdata.append("\n");

        while (z < model->rowCount()) {

        x = 0;

        while (x < model->columnCount()) {

        if (!ui->afficher->isColumnHidden(x)) {


        exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


        if (model->columnCount() - x != counthidden)
        {
            exportdata.append(";");

        }
        else
        {
        exportdata.append("\n");

        }
        }

        x++;

        }
        exportdata.append("\n");

        z++;
        }



           QFile file;

           if (!linki.isEmpty()) {

         file.setFileName(linki);

                if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

                    return;
        }
        QByteArray ttext;

        ttext.append(exportdata);

        file.write(ttext);
}

void MainWindow::on_fichiertxt_agent_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQueryModel  *model = new QSqlQueryModel() ;

    QString linki = QFileDialog::getSaveFileName(this, tr("Export TXT"),"/agent.txt", tr("Comma Separated Values (*.txt)"));


    ag=new (agent);

        int x = 0;

        QString exportdata;

        model=ag->afficher();

        int counthidden = 0, jint = 0;

        while (jint < model->columnCount()) {

        counthidden+=ui->tabagent->isColumnHidden(jint);

        jint++;
        }


        while (x < model->columnCount())
        {

        if (!ui->tabagent->isColumnHidden(x))
        {

        exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());

        //msgbox(exportdata);

        if (model->columnCount() - x != counthidden)

        exportdata.append(";");

        else

        exportdata.append("\n");

        }
        x++;

        }

        int z = 0;

        exportdata.append("\n");

        while (z < model->rowCount()) {

        x = 0;

        while (x < model->columnCount()) {

        if (!ui->afficher->isColumnHidden(x)) {


        exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


        if (model->columnCount() - x != counthidden)
        {
            exportdata.append(";");

        }
        else
        {
        exportdata.append("\n");

        }
        }

        x++;

        }
        exportdata.append("\n");

        z++;
        }



           QFile file;

           if (!linki.isEmpty()) {

         file.setFileName(linki);

                if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

                    return;
        }
        QByteArray ttext;

        ttext.append(exportdata);

        file.write(ttext);
}

void MainWindow::on_fichiertxt_stock_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQueryModel  *model = new QSqlQueryModel() ;

    QString linki = QFileDialog::getSaveFileName(this, tr("Export TXT"),"/stock.txt", tr("Comma Separated Values (*.txt)"));


    st=new (stock);

        int x = 0;

        QString exportdata;

        model=st->afficher();

        int counthidden = 0, jint = 0;

        while (jint < model->columnCount()) {

        counthidden+=ui->tabstock->isColumnHidden(jint);

        jint++;
        }


        while (x < model->columnCount())
        {

        if (!ui->tabstock->isColumnHidden(x))
        {

        exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());

        //msgbox(exportdata);

        if (model->columnCount() - x != counthidden)

        exportdata.append(";");

        else

        exportdata.append("\n");

        }
        x++;

        }

        int z = 0;

        exportdata.append("\n");

        while (z < model->rowCount()) {

        x = 0;

        while (x < model->columnCount()) {

        if (!ui->afficher->isColumnHidden(x)) {


        exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


        if (model->columnCount() - x != counthidden)
        {
            exportdata.append(";");

        }
        else
        {
        exportdata.append("\n");

        }
        }

        x++;

        }
        exportdata.append("\n");

        z++;
        }



           QFile file;

           if (!linki.isEmpty()) {

         file.setFileName(linki);

                if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

                    return;
        }
        QByteArray ttext;

        ttext.append(exportdata);

        file.write(ttext);
}

void MainWindow::on_fichiertxt_client_clicked()
{QSound *sound= new QSound(":/img/click.wav");
    sound->play();
    QSqlQueryModel  *model = new QSqlQueryModel() ;

    QString linki = QFileDialog::getSaveFileName(this, tr("Export TXT"),"/client.txt", tr("Comma Separated Values (*.txt)"));


    cll=new (client);

        int x = 0;

        QString exportdata;

        model=cll->afficher();

        int counthidden = 0, jint = 0;

        while (jint < model->columnCount()) {

        counthidden+=ui->tabclient->isColumnHidden(jint);

        jint++;
        }


        while (x < model->columnCount())
        {

        if (!ui->tabclient->isColumnHidden(x))
        {

        exportdata.append(model->headerData(x,Qt::Horizontal,Qt::DisplayRole).toString());

        //msgbox(exportdata);

        if (model->columnCount() - x != counthidden)

        exportdata.append(";");

        else

        exportdata.append("\n");

        }
        x++;

        }

        int z = 0;

        exportdata.append("\n");

        while (z < model->rowCount()) {

        x = 0;

        while (x < model->columnCount()) {

        if (!ui->afficher->isColumnHidden(x)) {


        exportdata.append(model->data(model->index(z,x),Qt::DisplayRole).toString());


        if (model->columnCount() - x != counthidden)
        {
            exportdata.append(";");

        }
        else
        {
        exportdata.append("\n");

        }
        }

        x++;

        }
        exportdata.append("\n");

        z++;
        }



           QFile file;

           if (!linki.isEmpty()) {

         file.setFileName(linki);

                if (!file.open(QIODevice::WriteOnly | QIODevice::Text))

                    return;
        }
        QByteArray ttext;

        ttext.append(exportdata);

        file.write(ttext);
}

void MainWindow::on_statitisque_agent_clicked()
{
    agent a1(125.


             ,"nom","prenom","role","mail");
    agent a2(545,"nom","prenom","role","mail");
    agent a3(25,"nom","prenom","role","mail");
    agent a4(998,"nom","prenom","role","mail");
    agent a5(78,"nom","prenom","role","mail");
    agent a6(369,"nom","prenom","role","mail");
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
    agent a;

    this->ui->stackedWidget->addWidget(chartView);
     a.statistique();
    ui->stackedWidget->currentWidget()->hide();
}


