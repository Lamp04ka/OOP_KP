#ifndef DAYS_IN_WEEK_H
#define DAYS_IN_WEEK_H
#include <string>

class Days_in_week
{
    enum days_in_week{
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };
    days_in_week day;
public:
    Days_in_week();
    Days_in_week(int);
    std::string getDays_in_week();
    int getDays_in_weekInt();
};

#endif // DAYS_IN_WEEK_H
