#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include <QMessageBox>


login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("LOGIN");
    setWindowIcon(QIcon(":/img/icon.png"));
    /*QPixmap pix(":/img/Books.jpg");
    ui->label_pix->setPixmap(pix);
    QPixmap pix_log_img1(":/img/loginImg1.png");
    ui->label_Login_img1->setPixmap(pix_log_img1);*/
}

login::~login()
{
    delete ui;
}




void login::on_PBconnexion_clicked()
{
    QString username =ui->LEidentifiant->text();
    QString Password =ui->LEmotdepasse->text();
    if(username =="" && Password =="")
    {
        //ui->statusBar->showMessage("username and password is not correct");
       QMessageBox::information(this,"Login","username and password is correct");
       mainwindow = new MainWindow(this);
       close();
       mainwindow->show();
    }
    else
    {
        QMessageBox::warning(this,"Login","username and password is not correct");
    }
}
