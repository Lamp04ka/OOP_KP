#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "admin.h"
#include "bd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ShowLessons(QList<lesson>);
signals:
    //void sendData(BD*);


private slots:
    void on_pushButton_2_clicked();
    void on_pushButtonRun_clicked();

private:
    Ui::MainWindow *ui;
    Login *logWindow;
    BD data;
};
#endif // MAINWINDOW_H
