#include "admin.h"
#include "ui_admin.h"
#include <QRegExpValidator>

#define NUMBER "[0-9]\\d{0,4}"
#define CHARACTER_RUS "[А-Я а-я.-]{0,20}"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    data.readPredmet();
    ShowPredmet();

    data.readGrupps();
    ShowGrupps();

    data.readTeachers();
    ShowTeathers();

    data.readCabs();
    ShowCabs();

    data.readPlan();
    ShowPlan();

    data.readLessons();
    ShowLessons();

    QRegExp num(NUMBER);
    QRegExp char_rus(CHARACTER_RUS);
    QRegExpValidator *id = new QRegExpValidator(num,this);
    QRegExpValidator *name = new QRegExpValidator(char_rus,this);

    ui->lineEditIdPredmet->setValidator(id);
    ui->lineEditNamePredmet->setValidator(name);

    ui->lineEditKolStud->setValidator(id);
    ui->lineEditNumPotok->setValidator(id);
    ui->lineEditNumPotok->setValidator(id);

    ui->lineEditIdPredmet_2->setValidator(id);
    ui->lineEditIdPlana->setValidator(id);
    ui->lineEditIdTeacher_2->setValidator(id);
    ui->lineEditIdPara->setValidator(id);
    ui->lineEditKolHours->setValidator(id);

    ui->lineEditIdTeacher->setValidator(id);
    ui->lineEditIdPredmeInTeacher->setValidator(id);
    ui->lineEditNameFIO_Teacher->setValidator(name);

    ui->lineEditIdTeacher_TT->setValidator(id);
    ui->lineEditIdPredmeInLesson->setValidator(id);


}

Admin::~Admin()
{
    delete ui;
}

void Admin::ShowPredmet()
{
    ui->tableWidgetPredmet->setColumnCount(2);
    ui->tableWidgetPredmet->setRowCount(data.getPredmet().size());
    ui->tableWidgetPredmet->setHorizontalHeaderLabels(QStringList()<<"Код Д."<<"Дисциплина");
    ui->tableWidgetPredmet->verticalHeader()->setVisible(false);
    ui->tableWidgetPredmet->horizontalHeader()->resizeSection(0, 50);
    for(int i=0;i<this->data.getPredmet().size();i++)
    {
        ui->tableWidgetPredmet->setItem(i,0,new QTableWidgetItem(QString::number(data.getPredmet()[i].getIdPredmet())));
        ui->tableWidgetPredmet->setItem(i,1,new QTableWidgetItem(QString::fromUtf8(data.getPredmet()[i].getNamePredmet().data(),data.getPredmet()[i].getNamePredmet().size())));
    }
}

void Admin::ShowPlan()
{
    ui->tableWidgetUchPlan->setColumnCount(6);
    ui->tableWidgetUchPlan->setRowCount(data.getPlan().size());
    ui->tableWidgetUchPlan->horizontalHeader()->resizeSection(0, 50);
    ui->tableWidgetUchPlan->horizontalHeader()->resizeSection(2, 40);
    ui->tableWidgetUchPlan->horizontalHeader()->resizeSection(3, 40);
    ui->tableWidgetUchPlan->horizontalHeader()->resizeSection(4, 70);
    ui->tableWidgetUchPlan->horizontalHeader()->resizeSection(5, 60);
    ui->tableWidgetUchPlan->setHorizontalHeaderLabels(QStringList()<<"Код Н."<<"Дисциплина"<<"Часов"<<"Тип"<<"№ Г. или П."<<"ID препд.");
    ui->tableWidgetUchPlan->verticalHeader()->setVisible(false);
    for(int i=0;i<this->data.getPlan().size();i++)
    {
        ui->tableWidgetUchPlan->setItem(i,0,new QTableWidgetItem(QString::number(data.getPlan()[i].getIdPlan())));
        ui->tableWidgetUchPlan->setItem(i,1,new QTableWidgetItem(QString::fromUtf8(data.getPlan()[i].getNamePredmet().data(),data.getPlan()[i].getNamePredmet().size())));
        ui->tableWidgetUchPlan->setItem(i,2,new QTableWidgetItem(QString::number(data.getPlan()[i].getKolHours())));
        ui->tableWidgetUchPlan->setItem(i,3,new QTableWidgetItem(data.getPlan()[i].getType()));
        ui->tableWidgetUchPlan->setItem(i,4,new QTableWidgetItem(QString::fromUtf8(data.getPlan()[i].getNameGP().data(),data.getPlan()[i].getNameGP().size())));
        ui->tableWidgetUchPlan->setItem(i,5,new QTableWidgetItem(QString::number(data.getPlan()[i].getIdTeacher())));
    }
}

void Admin::ShowGrupps()
{
    ui->tableWidgetGrupps->setColumnCount(3);
    ui->tableWidgetGrupps->setRowCount(data.getGrupps().size());
    ui->tableWidgetGrupps->setHorizontalHeaderLabels(QStringList()<<"Группа"<<"Кол. Студентов"<<"Поток");
    ui->tableWidgetGrupps->verticalHeader()->setVisible(false);
    ui->tableWidgetGrupps->horizontalHeader()->resizeSection(0, 50);
    ui->tableWidgetGrupps->horizontalHeader()->resizeSection(1, 40);
    ui->tableWidgetGrupps->horizontalHeader()->resizeSection(2, 50);
    for(int i=0;i<this->data.getGrupps().size();i++)
    {
        ui->tableWidgetGrupps->setItem(i,0,new QTableWidgetItem(QString::fromUtf8(data.getGrupps()[i].getNameGrupp().data(),data.getGrupps()[i].getNameGrupp().size())));
        ui->tableWidgetGrupps->setItem(i,1,new QTableWidgetItem(QString::number(data.getGrupps()[i].getKolStud())));
        ui->tableWidgetGrupps->setItem(i,2,new QTableWidgetItem(QString::fromUtf8(data.getGrupps()[i].getNumPotoka().data(),data.getGrupps()[i].getNumPotoka().size())));
    }
}

void Admin::ShowTeathers()
{
    QString buff="";
    ui->tableWidgetTeacher->setColumnCount(4);
    ui->tableWidgetTeacher->setRowCount(data.getTeachers().size());
    ui->tableWidgetTeacher->setHorizontalHeaderLabels(QStringList()<<"ID преп."<<"Фамилия И.О."<<"Должность"<<"Коды дисциплин");
    ui->tableWidgetTeacher->verticalHeader()->setVisible(false);
    ui->tableWidgetTeacher->horizontalHeader()->resizeSection(0, 50);
    ui->tableWidgetTeacher->horizontalHeader()->resizeSection(3, 100);
    for(int i=0;i<this->data.getTeachers().size();i++)
    {
        ui->tableWidgetTeacher->setItem(i,0,new QTableWidgetItem(QString::number(data.getTeachers()[i].getIdTeacher())));
        ui->tableWidgetTeacher->setItem(i,1,new QTableWidgetItem(QString::fromUtf8(data.getTeachers()[i].getNameTeather().data(),data.getTeachers()[i].getNameTeather().size())));
        ui->tableWidgetTeacher->setItem(i,2,new QTableWidgetItem(QString::fromUtf8(data.getTeachers()[i].getPosition().data(),data.getTeachers()[i].getPosition().size())));
        for(int j=0;j<data.getTeachers()[i].getPredmetIdInTeacher().size();j++){
            buff+=QString::number(data.getTeachers()[i].getPredmetIdInTeacher()[j]);
            if(j+1==data.getTeachers()[i].getPredmetIdInTeacher().size())
                buff+=";";
            else
                buff+=",";
        }
        ui->tableWidgetTeacher->setItem(i,3,new QTableWidgetItem(buff));
        buff="";
    }
}

void Admin::ShowCabs()
{
    ui->tableWidgetCab->setColumnCount(2);
    ui->tableWidgetCab->setRowCount(data.getCabs().size());
    ui->tableWidgetCab->setHorizontalHeaderLabels(QStringList()<<"Аудитория"<<"Адрес");
    ui->tableWidgetCab->verticalHeader()->setVisible(false);
    ui->tableWidgetCab->horizontalHeader()->resizeSection(0, 70);
    ui->tableWidgetCab->horizontalHeader()->resizeSection(1, 125);
    for(int i=0;i<this->data.getCabs().size();i++)
    {
        ui->tableWidgetCab->setItem(i,0,new QTableWidgetItem(QString::fromUtf8(data.getCabs()[i].getCab().data(),data.getCabs()[i].getCab().size())));
        ui->tableWidgetCab->setItem(i,1,new QTableWidgetItem(QString::fromUtf8(data.getCabs()[i].getAddress().data(),data.getCabs()[i].getAddress().size())));
    }
}

void Admin::ShowLessons()
{
    ui->tableWidgetTimeTable->setColumnCount(10);
    ui->tableWidgetTimeTable->setRowCount(data.getLessons().size());
    ui->tableWidgetTimeTable->setHorizontalHeaderLabels(QStringList()<<"id"<<"День"<<"Пара"<<"Начало"<<"Конец"<<"Группа(ы)"<<"Предмет"<<"Тип"<<"Аудитория"<<"Преподаватель");
    ui->tableWidgetTimeTable->verticalHeader()->setVisible(false);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(0, 20);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(2, 50);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(3, 50);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(4, 50);
    ui->tableWidgetTimeTable->horizontalHeader()->resizeSection(7, 40);
    for(int i=0;i<this->data.getLessons().size();i++)
    {
        ui->tableWidgetTimeTable->setItem(i,0,new QTableWidgetItem(QString::number(data.getLessons()[i].getIdLesson())));
        ui->tableWidgetTimeTable->setItem(i,1,new QTableWidgetItem(QString::fromUtf8(data.getLessons()[i].getDays_in_week().data(),data.getLessons()[i].getDays_in_week().size())));
        ui->tableWidgetTimeTable->setItem(i,2,new QTableWidgetItem(QString::number(data.getLessons()[i].getNumberPara())));
        ui->tableWidgetTimeTable->setItem(i,3,new QTableWidgetItem(data.getLessons()[i].getStart()));
        ui->tableWidgetTimeTable->setItem(i,4,new QTableWidgetItem(data.getLessons()[i].getEnd()));
        if(data.getLessons()[i].getName_GP()[0]!='P')
             ui->tableWidgetTimeTable->setItem(i,5,new QTableWidgetItem(QString::fromUtf8(data.getLessons()[i].getName_GP().data(),data.getLessons()[i].getName_GP().size())));
        else{
            QString grupps="";
            for(int j=0;j<data.getGrupps().size();j++){
                if(data.getGrupps()[j].getNumPotoka()==data.getLessons()[i].getName_GP()){
                    if(grupps!="")
                        grupps+=",";
                    grupps+=QString::fromUtf8(data.getGrupps()[j].getNameGrupp().data(),data.getGrupps()[j].getNameGrupp().size());
                }
            }
            ui->tableWidgetTimeTable->setItem(i,5,new QTableWidgetItem(grupps));
        }
         ui->tableWidgetTimeTable->setItem(i,6,new QTableWidgetItem(QString::fromUtf8(data.getLessons()[i].getNamePredmet().data(),data.getLessons()[i].getNamePredmet().size())));
         ui->tableWidgetTimeTable->setItem(i,7,new QTableWidgetItem(data.getLessons()[i].getType()));
         std::string cab="";
         cab+=data.getLessons()[i].getCab();
         cab+=" ";
         cab+=data.getLessons()[i].getAddress();
         ui->tableWidgetTimeTable->setItem(i,8,new QTableWidgetItem(QString::fromUtf8(cab.data(),cab.size())));
         ui->tableWidgetTimeTable->setItem(i,9,new QTableWidgetItem(QString::fromUtf8(data.getLessons()[i].getNameTeather().data(),data.getLessons()[i].getNameTeather().size())));
    }
}


void Admin::on_pushButtonLogout_clicked()
{
    this->close();
    emit lastWindow();
}

void Admin::on_pushButtonAddPredmet_clicked()
{
   if(!ui->lineEditNamePredmet->text().isEmpty()){
         if(!data.addPredmet(ui->lineEditNamePredmet->text()))
             QMessageBox::warning(this, "Добавление дисциплина", "Такая дисциплина уже есть");
         else{
             ShowPredmet();
             data.writePredmet();
         }
   }
   else  QMessageBox::warning(this, "Добавление дисциплины", "Поле \"Дисциплина\" пустое");
}



void Admin::on_pushButtonDeletePredmet_clicked()
{
    if(!ui->lineEditIdPredmet->text().isEmpty()){
        if(!data.deletePredmet(ui->lineEditIdPredmet->text().toInt()))
             QMessageBox::warning(this, "Удаление дисциплины", "Нет такого Код Д.");
        else {
            ShowPredmet();
            data.writePredmet();
            data.clearTeachers();
            data.readTeachers();
            data.writeTeachers();
            data.clearPlan();
            data.readPlan();
            data.writePlan();
            ShowPlan();
            ShowTeathers();
        }
    }
    else  QMessageBox::warning(this, "Удаление дисциплины", "Поле \"Код Д.\" пустое");
}


void Admin::on_pushButtonAddPlan_clicked()
{
    if(!ui->lineEditIdPredmet_2->text().isEmpty()&&!ui->lineEditKolHours->text().isEmpty()&&!ui->lineEditNumGrup_and_potok->text().isEmpty()&&!ui->lineEditIdTeacher_2->text().isEmpty()){
        if(ui->lineEditKolHours->text().toInt()>102)
            QMessageBox::warning(this, "Добавления нагрузки", "Количество часов не божет превышать 99");
        else if(!data.addPlan(ui->lineEditIdPredmet_2->text().toInt(),ui->lineEditKolHours->text().toInt(), ui->comboBoxTypePlan->currentIndex(),ui->lineEditNumGrup_and_potok->text(),ui->lineEditIdTeacher_2->text().toInt()))
             QMessageBox::warning(this, "Добавления нагрузки", "Нет такого Код Д. или токой группы/потока");
        else{
            ShowPlan();
            data.writePlan();
        }
    }
    else  QMessageBox::warning(this, "Ддаление дисциплины", "Поле \"Код Д.\"и/или \"Кол. Часов\", \"№ Г или П\",\"id препод.\" пустое");

}

void Admin::on_pushButtonDeletePlan_clicked()
{
    if(!ui->lineEditIdPlana->text().isEmpty()){
        if(!data.deletePlan(ui->lineEditIdPlana->text().toInt()))
             QMessageBox::warning(this, "Удаление нагрузки", "Нет такого Кода нагрузки");
        else {
            ShowPlan();
            data.writePlan();
        }
    }
    else    QMessageBox::warning(this, "Удаление нагрузки", "Поле \"Код нагрузки\" пустое");
}

void Admin::on_pushButtonAddGruppa_clicked()
{
    if(!ui->lineEditNumGrup->text().isEmpty()&&!ui->lineEditKolStud->text().isEmpty())
    {
         QString buff;
        if(!ui->lineEditNumPotok->text().isEmpty())
        {   buff="P";
            buff+=ui->lineEditNumPotok->text();
        }
        else
            buff="0";
        if(ui->lineEditNumGrup->text()[0]=="P")
            QMessageBox::warning(this, "Добавление группы", "Группа не можен начинаться на \"P\"");
        else {
            if(!data.addGrupp(ui->lineEditNumGrup->text(),ui->lineEditKolStud->text().toInt(),buff))
                QMessageBox::warning(this, "Добавление группы", "Такая группа уже есть");
            else{
                ShowGrupps();
                data.writeGrupps();
            }
        }

    }
    else    QMessageBox::warning(this, "Добавление группы", "Поле \"№ Группы\" или \"Количество студентов\" пустое");
}

void Admin::on_pushButtonDeleteGruppa_clicked()
{
    if(!ui->lineEditNumGrup->text().isEmpty()){
        if(!data.deleteGruppa(ui->lineEditNumGrup->text()))
            QMessageBox::warning(this, "Удаление группы", "Нет такого № Группы.");
        else{
            ShowGrupps();
            data.writeGrupps();
        }
    }
    else    QMessageBox::warning(this, "Удаление группы", "Поле \"№ Группы\" пустое");
}

void Admin::on_pushButtonAddPotok_clicked()
{
    QString buff="P";
    buff+=ui->lineEditNumPotok->text();
    if(!ui->lineEditNumGrup->text().isEmpty()&&!ui->lineEditNumPotok->text().isEmpty())
    {
        if(!data.rePotok(ui->lineEditNumGrup->text(),buff))
             QMessageBox::warning(this, "Изменение потока", "Нет такого № Группы.");
        else {
            ShowGrupps();
            data.writeGrupps();
        }
    }
    else        QMessageBox::warning(this, "Изменение потока", "Поле \"№ Группы\" или \"№ Потока\" пустое");
}

void Admin::on_pushButtonAddTeacher_clicked()
{
    if(!ui->lineEditNameFIO_Teacher->text().isEmpty()){
        data.addTeacher(ui->lineEditNameFIO_Teacher->text().toStdString(),ui->comboBoxPosition->currentIndex());
        ShowTeathers();
        data.writeTeachers();
    }
    else QMessageBox::warning(this, "Добавление преподавателя", "Поле \"Фамилия И.О.\" пустое");

}

void Admin::on_pushButtonDeleteTeacher_clicked()
{
    if(!ui->lineEditIdTeacher->text().isEmpty()){
        if(!data.deleteTeacher(ui->lineEditIdTeacher->text().toInt()))
             QMessageBox::warning(this, "Удаление преподавателя", "Нет такого ID преподавателя");
        else {
            ShowTeathers();
            data.writeTeachers();
        }
    }
    else    QMessageBox::warning(this, "Удаление преподавателя", "Поле \"ID преподавателя\" пустое");

}

void Admin::on_pushButtonAddPredmetInTeacher_clicked()
{
    if(!ui->lineEditIdTeacher->text().isEmpty()&&!ui->lineEditIdPredmeInTeacher->text().isEmpty()){
        int flag=data.addPredmetInTeather(ui->lineEditIdTeacher->text().toInt(),ui->lineEditIdPredmeInTeacher->text().toInt());
        if(1==flag)
            QMessageBox::warning(this, "Добавление Д. Преподавателю", "Нет такого ID преподавателя или ID дисциплины");
        else if(0==flag){
            ShowTeathers();
            data.writeTeachers();
        }
        else    QMessageBox::warning(this, "Добавление Д. Преподавателю", "У преподавателя уже есть такая дисциплина");
    }
    else    QMessageBox::warning(this, "Добавление Д. Преподавателю", "Поля \"ID преподавателя\" или \"ID дисциплины\"");
}

void Admin::on_pushButtonDeletePredmetInTeacher_clicked()
{
    if(!ui->lineEditIdTeacher->text().isEmpty()&&!ui->lineEditIdPredmeInTeacher->text().isEmpty()){
        if(!data.deletePredmetInTeather(ui->lineEditIdTeacher->text().toInt(),ui->lineEditIdPredmeInTeacher->text().toInt()))
            QMessageBox::warning(this, "Добавление Д. Преподавателю", "Нет такого ID преподавателя или ID дисциплины");
        else {
            ShowTeathers();
            data.writeTeachers();
        }
    }
    else    QMessageBox::warning(this, "Добавление Д. Преподавателю", "Поля \"ID преподавателя\" или \"ID дисциплины\"");
}


void Admin::on_pushButtonAddCab_clicked()
{
    if(!ui->lineEditCab->text().isEmpty())    {
        if(!data.addCabs(ui->lineEditCab->text().toStdString(),ui->comboBoxAddress->currentIndex()))
            QMessageBox::warning(this, "Добавление Аудитории", "Такая аудитория уже есть");
        else {
              data.writeCabs();
              ShowCabs();
        }
    }
    else    QMessageBox::warning(this, "Добавление Аудитории", "Поле аудитория пустое");
}

void Admin::on_pushButtonDeleteCab_clicked()
{
    if(!ui->lineEditCab->text().isEmpty())    {
        if(!data.deleteCabs(ui->lineEditCab->text().toStdString(),ui->comboBoxAddress->currentIndex()))
            QMessageBox::warning(this, "Удаление Аудитории", "Такой аудитории нет");
        else {
              data.writeCabs();
              ShowCabs();
        }
    }
    else    QMessageBox::warning(this, "Удаление Аудитории", "Поле аудитория пустое");
}

void Admin::on_pushButtonAddTT_clicked()
{
    if(ui->lineEditIdPredmeInLesson->text().isEmpty())
        QMessageBox::warning(this, "Добавления пары", "Поле \"Код дисциплины\" пустое");
    else if(ui->lineEditIdTeacher_TT->text().isEmpty())
        QMessageBox::warning(this, "Добавления пары", "Поле \"ID преподавателя\" пустое");
    else if(ui->lineEditCab_TT->text().isEmpty())
        QMessageBox::warning(this, "Добавления пары", "Поле \"Аудитория\" пустое");
    else{
        int day=ui->comboBoxDay->currentIndex();
        int para=ui->comboBoxParaTT->currentIndex();
        int index_type=ui->comboBoxTypePlan_TT->currentIndex();
        int id_predmet=ui->lineEditIdPredmeInLesson->text().toInt();
        int id_teacher=ui->lineEditIdTeacher_TT->text().toInt();
        int index_cab=ui->comboBoxAddress_TT->currentIndex();
        QString cab=ui->lineEditCab_TT->text();
        QString GP=ui->lineEditNumGrup_and_potok_TT->text();
        int flag=data.addLesson(day,para,index_type,id_predmet,id_teacher,index_cab,cab,GP);
        switch (flag) {
        case 0:
            QMessageBox::warning(this, "Добавления пары", "Нет такого кода дисциплины");
            break;
        case 1:
            QMessageBox::warning(this, "Добавления пары", "Нет такого id преподавателя");
            break;
        case 2:
            QMessageBox::warning(this, "Добавления пары", "Нет такой аудитории");
            break;
        case 3:
            QMessageBox::warning(this, "Добавления пары", "Нет такой группы или потока");
            break;
        case 4:
            QMessageBox::warning(this, "Добавления пары", "Аудитория занята");
            break;
        case 5:
            QMessageBox::warning(this, "Добавления пары", "У группы или потока в этот момент есть занятие");
            break;
        case 6:
            QMessageBox::warning(this, "Добавления пары", "У преподавателя в этот момент есть занятие");
            break;
        case 7:
            data.writeLessons();
            ShowLessons();
            break;
        }
    }

}

void Admin::on_pushButtonDeleteTT_clicked()
{
    if(ui->lineEditIdPara->text().isEmpty())
        QMessageBox::warning(this, "Удаления пары", "Поле \"Код пары\" пустое");
    else if(data.deleteLesson(ui->lineEditIdPara->text().toInt())){
        data.writeLessons();
        ShowLessons();
    }
    else QMessageBox::warning(this, "Удаления пары", "Нет такого кода пары");
}

void Admin::on_pushButtonDeleteAllTT_clicked()
{
    data.deleteLessonAll();
    data.writeLessons();
    ShowLessons();
}

void Admin::on_pushButtonGeneratTT_clicked()
{
    if(!data.getLessons().isEmpty())
         QMessageBox::warning(this, "Генерация расписания", "Очистите расписание перед его генерацией");
    else{
    data.GenerateTimeTable();
    ShowLessons();
    data.writeLessons();
    }
}
