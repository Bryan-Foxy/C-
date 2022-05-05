#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_10_clicked()
{
    //QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Endezoumou Bryan/Downloads/hopki nsang rhodes pauline yellena-2.pdf"));
}

void MainWindow::on_regis_certificate_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Endezoumou Bryan/Downloads/ilovepdf_extracted-pages(1)/Attestation dinscription.pdf"));
}

void MainWindow::on_btn_signin_clicked()
{
    //ui->statusbar->showMessage("Affichage de la liste des équipements...");
    ui->Interfaces->setCurrentIndex(2);
}

void MainWindow::on_home_btn_clicked()
{
    ui->statusbar->showMessage("Home");
    ui->Interfaces->setCurrentIndex(2);
}

void MainWindow::on_setting_btn_clicked()
{
        ui->statusbar->showMessage("Login Admins");
        ui->Interfaces->setCurrentIndex(3);
}

void MainWindow::on_logout_btn_clicked()
{
    ui->statusbar->showMessage("Deconnexion...");
        ui->Interfaces->setCurrentIndex(0);
}

void MainWindow::on_signin_btn2_clicked()
{
    ui->statusbar->showMessage("Connection part admins...");
        ui->Interfaces->setCurrentIndex(4);
}

void MainWindow::on_back_btn_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_back_btn_2_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_addStudent_clicked()
{
    ui->statusbar->showMessage("Sign UP Student...");
        ui->Interfaces->setCurrentIndex(1);
}

void MainWindow::on_back_btn3_clicked()
{
    ui->statusbar->showMessage("Back...");
        ui->Interfaces->setCurrentIndex(4);
}

void MainWindow::on_back_btn2_clicked()
{
    ui->statusbar->showMessage("Back Login...");
        ui->Interfaces->setCurrentIndex(3);
}

void MainWindow::on_back_btn_clicked()
{
    ui->statusbar->showMessage("Back home...");
        ui->Interfaces->setCurrentIndex(2);
}

void MainWindow::on_cert_sucess_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Endezoumou Bryan/Downloads/ilovepdf_extracted-pages/attestation réussite.pdf"));
}

void MainWindow::on_cert_payment_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Endezoumou Bryan/Downloads/ilovepdf_extracted-pages/attestation de paiement.pdf"));
}

void MainWindow::on_cert_attendance_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Endezoumou Bryan/Downloads/ilovepdf_extracted-pages(1)/Attestation de présence.pdf"));
}
