#include "login.h"
#include "ui_login.h"
#include "user.h"

/*login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}*/

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_connect_clicked()
{

    QString username = ui->utilisateur->text();
    QString password = ui->motdepasse->text();

    user user(username,password);

    int login = user.login();

    if(login == 0){

        mainwindow.show();
        this->destroy();

    }else if (login == 1) {

        QMessageBox::critical (this, "Error", "Something went wrong !");

    }else {

        QMessageBox::critical (this, "Error", "Invalid username or password !");
    }

}
