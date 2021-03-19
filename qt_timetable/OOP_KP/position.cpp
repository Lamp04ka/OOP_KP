#include "position.h"

Position::Position()
{

}

Position::Position(int i_p)
{
    switch (i_p) {
    case 0:
        this->position=this->Asistent;
        break;
    case 1:
        this->position=this->Starschi_prepodavatel;
        break;
    case 2:
        this->position=this->Docent;
        break;
    case 3:
        this->position=this->Profesor;
        break;
    }
}


std::string Position::getPosition(){
    switch (this->position) {
    case position_teacher::Asistent:
        return "Асистент";
        break;
    case position_teacher::Starschi_prepodavatel:
        return "Старший преподаватель";
        break;
    case position_teacher::Docent:
        return "Доцент";
        break;
    case position_teacher::Profesor:
        return "Профессор";
        break;
    }
}
int Position::getPositionInt(){
    switch (this->position) {
    case position_teacher::Asistent:
        return 0;
        break;
    case position_teacher::Starschi_prepodavatel:
        return 1;
        break;
    case position_teacher::Docent:
        return 2;
        break;
    case position_teacher::Profesor:
        return 3;
        break;
    }
}
