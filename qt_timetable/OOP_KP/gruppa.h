#ifndef GRUPPA_H
#define GRUPPA_H
#include <string>
#include <QObject>


class Gruppa
{
    std::string name_gruppa;
    int kol_stud;
    std::string num_potoka="0";
public:
    Gruppa();
    Gruppa(std::string,int,std::string);
    std::string getNameGrupp();
    int getKolStud();
    std::string getNumPotoka();
    void setPotok(std::string);

    bool operator<(const Gruppa& data) const
        {
            return name_gruppa < data.name_gruppa;
        }
};

#endif // GRUPPA_H
