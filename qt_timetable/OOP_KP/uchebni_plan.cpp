#include "uchebni_plan.h"

Uchebni_plan::Uchebni_plan()
{

}
Uchebni_plan::Uchebni_plan(int i_id_plan,int i_kol_hours,int i_type,std::string i_name,Predmet i_p,Teacher i_t):Predmet(i_p),Type_Lesson(i_type),Teacher(i_t)
{
    this->kol_hours=i_kol_hours;
    this->id_plan = i_id_plan;
    this->name_GP=i_name;
}
int Uchebni_plan::getKolHours(){return this->kol_hours;}
int Uchebni_plan::getIdPlan(){return this->id_plan;}
std::string Uchebni_plan::getNameGP(){return this->name_GP;}

