#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_10_clicked();

    void on_regis_certificate_clicked();

    void on_btn_signin_clicked();

    void on_home_btn_clicked();

    void on_setting_btn_clicked();

    void on_logout_btn_clicked();

    void on_signin_btn2_clicked();

    void on_back_btn_customContextMenuRequested(const QPoint &pos);

    void on_back_btn_2_customContextMenuRequested(const QPoint &pos);

    void on_addStudent_clicked();

    void on_back_btn3_clicked();

    void on_back_btn2_clicked();

    void on_back_btn_clicked();

    void on_cert_sucess_clicked();

    void on_cert_payment_clicked();

    void on_cert_attendance_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
