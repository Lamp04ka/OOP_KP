#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QList>
#include <string>

#include "bd.h"
#include "uchebni_plan.h"

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

    void ShowPredmet();
    void ShowPlan();
    void ShowGrupps();
    void ShowTeathers();
    void ShowCabs();
    void ShowLessons();
    BD returnBd(){return this->data;}

signals:
    void lastWindow();

private slots:
    void on_pushButtonLogout_clicked();

    void on_pushButtonAddPredmet_clicked();

    void on_pushButtonDeletePredmet_clicked();

    void on_pushButtonAddPlan_clicked();

    void on_pushButtonAddGruppa_clicked();

    void on_pushButtonDeleteGruppa_clicked();

    void on_pushButtonAddPotok_clicked();

    void on_pushButtonDeletePlan_clicked();

    void on_pushButtonAddTeacher_clicked();

    void on_pushButtonDeleteTeacher_clicked();

    void on_pushButtonAddPredmetInTeacher_clicked();

    void on_pushButtonDeletePredmetInTeacher_clicked();

    void on_pushButtonAddCab_clicked();

    void on_pushButtonDeleteCab_clicked();

    void on_pushButtonAddTT_clicked();

    void on_pushButtonDeleteTT_clicked();

    void on_pushButtonDeleteAllTT_clicked();

    void on_pushButtonGeneratTT_clicked();

private:
    Ui::Admin *ui;
    BD data;
};

#endif // ADMIN_H
