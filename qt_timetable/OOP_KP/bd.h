#ifndef BD_H
#define BD_H

#include <QFile>
#include <string>
#include <iostream>
#include <QString>

#include <QList>
#include <QDialog>
#include "QMessageBox"
#include "xlsxdocument.h"

#include "gruppa.h"
#include "predmet.h"
#include "uchebni_plan.h"
#include "para.h"
#include "teacher.h"
#include "cabinet.h"
#include "type_lesson.h"
#include "lesson.h"


class BD
{    
    QList<Predmet> predmet_data;
    QList<Uchebni_plan> plan_data;
    QList<Gruppa> grupps_data;
    QList<Teacher> teachers_data;
    QList<Cabinet> cabs_data;
    QList<lesson> lessons_data;

public:
    BD();
//////////////////////////////////////////Проверки
    bool wainGP(QList<std::string> G,std::string P,int day,int para);
    bool waitTeacher(int id_teacher,int day,int para);
    bool waitCabinet(int day,int para);
////////////////////////////////////////дисциплина
    void readPredmet();
    void writePredmet();
    void sortPredmet();
    bool addPredmet(QString);
    bool deletePredmet(int);
    QList<Predmet> getPredmet();
    Predmet returnPredmet(int);
//////////////////////////////////////////учебный план
    void readPlan();
    void writePlan();
    void clearPlan(){this->plan_data.clear();}
    void sortPlan();
    bool addPlan(int,int,int,QString,int);
    bool deletePlan(int);
    QList<Uchebni_plan> getPlan();
///////////////////////////////////////////группа
    void readGrupps();
    void writeGrupps();
    void sortGrupps();
    bool addGrupp(QString,int,QString);
    bool deleteGruppa(QString);
    bool rePotok(QString,QString);
    QList<Gruppa> getGrupps();
///////////////////////////////////////////препод.
    void readTeachers();
    void writeTeachers();
    void clearTeachers(){this->teachers_data.clear();};
    void sortTeachers();
    void addTeacher(std::string,int);
    bool deleteTeacher(int i_id);
    int addPredmetInTeather(int,int);
    bool deletePredmetInTeather(int,int);
    QList<Teacher> getTeachers();
///////////////////////////////////////////Аудитории
    void readCabs();
    void writeCabs();
    void sortCabs();
    bool addCabs(std::string,int);
    bool deleteCabs(std::string,int);
    QList<Cabinet> getCabs();
///////////////////////////////////////////Расписание
    void readLessons();
    void writeLessons();
    void sortLessons();
    int addLesson(int,int,int,int,int,int,QString,QString);
    bool deleteLesson(int);
    void deleteLessonAll();
    QList<lesson> getLessons();
    void GenerateTimeTable();
    QList<lesson> FindLessons(QString i_str,int index_day);

};

#endif // BD_H
