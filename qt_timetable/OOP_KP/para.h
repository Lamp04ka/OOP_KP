#ifndef PARA_H
#define PARA_H
#include <QString>

class Para
{
    QString start;
    QString end;
    int numberPara;
public:
    Para();
    Para(int);
    QString getStart();
    QString getEnd();
    int getNumberPara();
};

#endif // PARA_H
