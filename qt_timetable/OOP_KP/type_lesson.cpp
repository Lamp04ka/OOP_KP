#include "type_lesson.h"

Type_Lesson::Type_Lesson()
{

}
Type_Lesson::Type_Lesson(int i_index)
{
    switch (i_index) {
    case 0:
        this->type_plan=this->L;
        break;
    case 1:
        this->type_plan=this->LR;
        break;
    case 2:
        this->type_plan=this->KP;
        break;
    case 3:
        this->type_plan=this->KR;
        break;
    case 4:
        this->type_plan=this->PR;
        break;
    }
}

QString Type_Lesson::getType(){
    switch (this->type_plan) {
    case Type::L:
        return "Л";
    case Type::LR:
        return "ЛР";
    case Type::KP:
        return "КП";
    case Type::KR:
        return "КР";
    case Type::PR:
        return "ПР";
    }
}
int Type_Lesson::getTypeInt(){
        switch (this->type_plan) {
        case Type::L:
            return 0;
        case Type::LR:
            return 1;
        case Type::KP:
            return 2;
        case Type::KR:
            return 3;
        case Type::PR:
            return 4;
        }
}
