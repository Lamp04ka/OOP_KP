#ifndef PREDMET_H
#define PREDMET_H
#include <QString>

class Predmet
{
protected:
    int id_predmet;
    std::string name_predmet;
public:
    Predmet();
    Predmet(int,std::string);
    std::string getNamePredmet();
    int getIdPredmet();

    bool operator<(const Predmet& data) const
        {
            return id_predmet < data.id_predmet;
        }
};

#endif // PREDMET_H
