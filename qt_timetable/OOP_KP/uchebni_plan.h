#ifndef UCHEBNI_PLAN_H
#define UCHEBNI_PLAN_H
#include "predmet.h"
#include <string>
#include <QString>
#include "type_lesson.h"
#include "teacher.h"

class Uchebni_plan : public Predmet, public Type_Lesson,public Teacher
{
    int id_plan;
    int kol_hours;;
    std::string name_GP;
public:
    Uchebni_plan();
    Uchebni_plan(int,int,int,std::string,Predmet i_p,Teacher i_t);
    int getKolHours();
    int getIdPlan();
    std::string getNameGP();
    bool operator<(const Uchebni_plan& data) const
        {
            return id_plan < data.id_plan;
        }
};

#endif // UCHEBNI_PLAN_H
