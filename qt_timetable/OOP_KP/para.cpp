#include "para.h"

Para::Para(){}

Para::Para(int num)
{
    switch (num) {
    case 1:
        this->start="9.30";
        this->end="11.00";
        this->numberPara=1;
        break;

    case 2:
        this->start="11.10";
        this->end="12.40";
        this->numberPara=2;
        break;

    case 3:
        this->start="13.00";
        this->end="14.30";
        this->numberPara=3;
        break;

    case 4:
        this->start="15.00";
        this->end="16.30";
        this->numberPara=4;
        break;

    case 5:
        this->start="16.40";
        this->end="18.10";
        this->numberPara=5;
        break;

    case 6:
        this->start="18.30";
        this->end="20.00";
        this->numberPara=6;
        break;
    }
}

QString Para::getStart(){return this->start;}
QString Para::getEnd(){return this->end;}
int Para::getNumberPara(){return this->numberPara;}
