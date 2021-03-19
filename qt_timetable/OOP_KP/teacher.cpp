#include "teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int i_id,std::string i_name,int position):Position(position)
{
    this->id_teacher=i_id;
    this->name_theaher=i_name;
}

void Teacher::addPredmetIdInTeacher(int i_id_predmet){    this->predmets.push_back(i_id_predmet); std::sort(predmets.begin(),predmets.end());}

std::string Teacher::getNameTeather(){return this->name_theaher;}

int Teacher::getIdTeacher(){return this->id_teacher;}

QList<int> Teacher::getPredmetIdInTeacher(){return this->predmets;}

void Teacher::deletePredmetIdInTeacher(int i_num){predmets.removeAt(i_num);}

