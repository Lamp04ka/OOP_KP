#include "predmet.h"

Predmet::Predmet()
{

}

Predmet::Predmet(int i_id, std::string i_name)
{
    this->id_predmet=i_id;
    this->name_predmet=i_name;
}
int Predmet::getIdPredmet(){return this->id_predmet;}
std::string Predmet::getNamePredmet(){return this->name_predmet;}

