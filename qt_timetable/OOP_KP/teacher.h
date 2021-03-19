#ifndef TEACHER_H
#define TEACHER_H
#include <string>
#include "position.h"
#include <QList>
#include <string>

class Teacher: public Position
{
    int id_teacher;
    std::string name_theaher;
    QList<int> predmets;
    
public:
    Teacher();
    Teacher(int,std::string,int);
    void addPredmetIdInTeacher(int);
    std::string getNameTeather();
    int getIdTeacher();
    QList<int> getPredmetIdInTeacher();
    void deletePredmetIdInTeacher(int);
    bool operator<(const Teacher& data) const
        {
            return id_teacher < data.id_teacher;
        }
};

#endif // TEACHER_H
