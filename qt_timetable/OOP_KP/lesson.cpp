#include "lesson.h"

lesson::lesson()
{

}

lesson::lesson(int i_id_lesson, int i_day,int i_num_para,int i_type_lesson,Cabinet i_cab,Predmet i_p,Teacher i_teacher,std::string i_name_GP)
    :Para(i_num_para), Teacher(i_teacher), Cabinet(i_cab), Predmet(i_p), Type_Lesson(i_type_lesson), Days_in_week(i_day)
{
    this->name_GP=i_name_GP;
    this->id_lesson=i_id_lesson;
}

std::string lesson::getName_GP(){return this->name_GP;}

int lesson::getIdLesson(){return this->id_lesson;}
