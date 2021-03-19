#ifndef POSITION_H
#define POSITION_H
#include <string>


class Position
{
    enum position_teacher
    {
        Asistent,
        Starschi_prepodavatel,
        Docent,
        Profesor
    };
    position_teacher position;
public:
    Position();
    Position(int);
    std::string getPosition();
    int getPositionInt();
};

#endif // POSITION_H
