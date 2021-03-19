#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logWindow = new Login();
    connect(logWindow, &Login::firstWindow,this, &MainWindow::show);
    connect(logWindow->getAdmin(), &Admin::lastWindow,this, &MainWindow::show);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowLessons(QList<lesson> i_lesson)
{
    ui->tableWidgetTimeTable->setColumnCount(9);
    ui->tableWidgetTimeTable->setRowCount(i_lesson.size());
    ui->tableWidgetTimeTable->setHorizontalHeaderLabels(QStringList()<<"День"<<"Пара"<<"Начало"<<"Конец"<<"Группа(ы)"<<"Предмет"<<"Тип"<<"Аудитория"<<"Преподаватель");
    ui->tableWidgetTimeTable->verticalHeader()->setVisible(false);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(1, 40);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(2, 50);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(3, 50);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(6, 40);
    for(int i=0;i<i_lesson.size();i++)
    {
        ui->tableWidgetTimeTable->setItem(i,0,new QTableWidgetItem(QString::fromUtf8(i_lesson[i].getDays_in_week().data(),i_lesson[i].getDays_in_week().size())));
        ui->tableWidgetTimeTable->setItem(i,1,new QTableWidgetItem(QString::number(i_lesson[i].getNumberPara())));
        ui->tableWidgetTimeTable->setItem(i,2,new QTableWidgetItem(i_lesson[i].getStart()));
        ui->tableWidgetTimeTable->setItem(i,3,new QTableWidgetItem(i_lesson[i].getEnd()));
        if(i_lesson[i].getName_GP()[0]!='P')
             ui->tableWidgetTimeTable->setItem(i,4,new QTableWidgetItem(QString::fromUtf8(i_lesson[i].getName_GP().data(),i_lesson[i].getName_GP().size())));
        else{
            QString grupps="";
            for(int j=0;j<data.getGrupps().size();j++){
                if(data.getGrupps()[j].getNumPotoka()==i_lesson[i].getName_GP()){
                    if(grupps!="")
                        grupps+=",";
                    grupps+=QString::fromUtf8(data.getGrupps()[j].getNameGrupp().data(),data.getGrupps()[j].getNameGrupp().size());
                }
            }
            ui->tableWidgetTimeTable->setItem(i,4,new QTableWidgetItem(grupps));
        }
         ui->tableWidgetTimeTable->setItem(i,5,new QTableWidgetItem(QString::fromUtf8(i_lesson[i].getNamePredmet().data(),i_lesson[i].getNamePredmet().size())));
         ui->tableWidgetTimeTable->setItem(i,6,new QTableWidgetItem(i_lesson[i].getType()));
         std::string cab="";
         cab+=i_lesson[i].getCab();
         cab+=" ";
         cab+=i_lesson[i].getAddress();
         ui->tableWidgetTimeTable->setItem(i,7,new QTableWidgetItem(QString::fromUtf8(cab.data(),cab.size())));
         ui->tableWidgetTimeTable->setItem(i,8,new QTableWidgetItem(QString::fromUtf8(i_lesson[i].getNameTeather().data(),i_lesson[i].getNameTeather().size())));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    logWindow->show();
    this->close();
}

void MainWindow::on_pushButtonRun_clicked()
{
    if(ui->lineEdit->text().isEmpty())
         QMessageBox::warning(this, "Hасписания", "Пустая строка");
    else{
        this->data=logWindow->getAdmin()->returnBd();
        QList<lesson> buff=data.FindLessons(ui->lineEdit->text(),ui->comboBox->currentIndex());
        ShowLessons(buff);
    }

}
