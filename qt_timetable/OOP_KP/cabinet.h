#ifndef CABINET_H
#define CABINET_H
#include <string>

class Cabinet
{
    std::string cab;
    enum adrs{
        BM67,
        G17,
        L14v
    };
    adrs address;
public:
    Cabinet();
    Cabinet(std::string,int);
    std::string getCab();
    std::string getAddress();
    int getAddressInt();
    bool operator<(const Cabinet& data) const
        {
            return cab < data.cab;
        }

};

#endif // COBINET_H
