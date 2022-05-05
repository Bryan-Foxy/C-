#ifndef LOGIN_H
#define LOGIN_H

//#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_connect_clicked();

private:
    Ui::login *ui;
    MainWindow mainwindow;
};

#endif // LOGIN_H
