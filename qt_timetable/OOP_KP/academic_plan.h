#ifndef ACADEMIC_PLAN_H
#define ACADEMIC_PLAN_H
#include "predmet.h"

class Academic_plan : public Predmet
{
    int id_plan;
    int academic_hours;
    int number_semester; 
public:
    Academic_plan();
    Academic_plan(int, int, int);
    int getIdPlan();
    int getAcademicHours();
    int getNumberSemester();
};

#endif // ACADEMIC_PLAN_H
