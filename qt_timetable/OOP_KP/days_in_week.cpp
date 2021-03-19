#include "days_in_week.h"

Days_in_week::Days_in_week()
{

}
Days_in_week::Days_in_week(int i_index)
{
    switch (i_index) {
    case 0:
        this->day=this->Monday;
        break;
    case 1:
        this->day=this->Tuesday;
        break;
    case 2:
        this->day=this->Wednesday;
        break;
    case 3:
        this->day=this->Thursday;
        break;
    case 4:
        this->day=this->Friday;
        break;
    case 5:
        this->day=this->Saturday;
        break;
    }
}


std::string Days_in_week::getDays_in_week(){
    switch (this->day) {
    case days_in_week::Monday:
        return "Понедельник";
        break;
    case days_in_week::Tuesday:
        return "Вторник";
        break;
    case days_in_week::Wednesday:
        return "Среда";
        break;
    case days_in_week::Thursday:
        return "Четверг";
        break;
    case days_in_week::Friday:
        return "Пятница";
        break;
    case days_in_week::Saturday:
        return "Суббота";
        break;

    }
}
int Days_in_week::getDays_in_weekInt(){
    switch (this->day) {
    case days_in_week::Monday:
        return 0;
        break;
    case days_in_week::Tuesday:
        return 1;
        break;
    case days_in_week::Wednesday:
        return 2;
        break;
    case days_in_week::Thursday:
        return 3;
        break;
    case days_in_week::Friday:
        return 4;
        break;
    case days_in_week::Saturday:
        return 5;
        break;
    }
}
