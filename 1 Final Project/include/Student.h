#ifndef STUDENT_H
#define STUDENT_H

#include <Courses.h>
#include <Profile.h>
#include <Enrol.h>
#include <iostream>

using namespace std;

class Student : public Profile, public Enrol, public Courses
{
public:
    Student()
    {
        setstudentinfo();
    }
    Student(int){}
    void setCourse();
    void displayCourse();
    void setstudentinfo();
    void display();
    virtual ~Student();
};

#endif // STUDENT_H
