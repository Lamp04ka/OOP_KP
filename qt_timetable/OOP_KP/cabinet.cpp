#include "cabinet.h"

Cabinet::Cabinet()
{

}

Cabinet::Cabinet(std::string i_cab,int i_address)
{
    this->cab=i_cab;
    switch (i_address) {
    case 0:
        this->address=adrs::BM67;
        break;
    case 1:
        this->address=adrs::G17;
        break;
    case 2:
        this->address=adrs::L14v;
        break;
    }
}

std::string Cabinet::getCab(){return this->cab;}
std::string Cabinet::getAddress(){
    switch (this->address) {
    case adrs::BM67:
        return "БМ 67";
        break;
    case adrs::G17:
        return "Гас. 15";
        break;
    case adrs::L14v:
        return "Лен. 14в";
        break;
    }
}

int Cabinet::getAddressInt(){
    switch (this->address) {
    case adrs::BM67:
        return 0;
        break;
    case adrs::G17:
        return 1;
        break;
    case adrs::L14v:
        return 2;
        break;
    }
}
