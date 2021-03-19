#ifndef LESSON_H
#define LESSON_H
#include "para.h"
#include "teacher.h"
#include "cabinet.h"
#include "predmet.h"
#include "type_lesson.h"
#include "days_in_week.h"

#include <string>

class lesson:public Para,public Teacher,public Cabinet,public Predmet,public Type_Lesson,public Days_in_week
{

    int id_lesson;
    std::string name_GP;

public:
    lesson();
    lesson(int i_id_lesson,int i_day,int i_num_para,int i_type_lesson,Cabinet i_cab,Predmet i_p,Teacher i_teacher,std::string i_name_GP);
    std::string getName_GP();
    int getIdLesson();
    bool operator<(const lesson& data) const
        {
            return id_lesson < data.id_lesson;
        }
};

#endif // LESSON_H
