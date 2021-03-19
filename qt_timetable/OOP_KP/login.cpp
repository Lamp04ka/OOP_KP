#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    adminWindow = new Admin;
}


Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString name,pass;
    QString ver_name="admin";
    QString ver_pass="12345";
    name = ui->log->text();
    pass= ui->pass->text();
    if(name==ver_name&&pass==ver_pass)
    {
        adminWindow->show();
        this->close();
    }
}

void Login::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}

