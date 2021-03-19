#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include "admin.h"


namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    Admin* getAdmin(){
        return this->adminWindow;
    };

signals:
    void firstWindow();//сигнал для основного окна на открытие

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    Admin *adminWindow;
};

#endif // LOGIN_H
