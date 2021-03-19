#ifndef TYPE_LESSON_H
#define TYPE_LESSON_H
#include <string>
#include <QString>

class Type_Lesson
{
    enum Type{L,LR,KP,KR,PR};
    Type  type_plan;
public:
    Type_Lesson();
    Type_Lesson(int);
    QString getType();
    int getTypeInt();

};

#endif // TYPE_LESSON_H
