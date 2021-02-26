#ifndef LECTURER_H
#define LECTURER_H

#include <Profile.h>
#include <Courses.h>

class Lecturer : public Profile, public Courses
{
private:
    string office;
public:
    void setLecturer();
    void display();
    void displayCourse();
    void setOffice();
    Lecturer()
    {
        setLecturer();
        setOffice();
        Courses::setCourse();
    }
    Lecturer(int){}
    virtual ~Lecturer();
};

#endif // LECTURER_H
