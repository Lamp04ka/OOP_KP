#include "academic_plan.h"

Academic_plan::Academic_plan()
{

}

Academic_plan::Academic_plan(int i_id_plan,int i_academic_hours, int i_number_semeste)
{
    this->id_plan=i_id_plan;
    this->academic_hours=i_academic_hours;
    this->number_semester=i_number_semeste;
}

int Academic_plan::getIdPlan(){return this->id_plan;}
int Academic_plan::getAcademicHours(){return this->number_semester;}
int Academic_plan::getNumberSemester(){return this->number_semester;}
