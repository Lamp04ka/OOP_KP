#include "gruppa.h"

Gruppa::Gruppa()
{

}
Gruppa::Gruppa(std::string i_name,int i_kol_stud,std::string i_num_potoka){
    this->name_gruppa=i_name;
    this->kol_stud=i_kol_stud;
    this->num_potoka=i_num_potoka;

}
std::string Gruppa::getNameGrupp(){return this->name_gruppa;}
int Gruppa::getKolStud(){return this->kol_stud;}
std::string Gruppa::getNumPotoka(){return this->num_potoka;}
void Gruppa::setPotok(std::string i_num_potok){this->num_potoka=i_num_potok;}
