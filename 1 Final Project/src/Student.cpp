#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "Password.h"
#include "Profile.h"
#include "Courses.h"
#include "Enrol.h"
#include "Student.h"
#include "Lecturer.h"
#include "Admin.h"

using namespace std;

void Student::display()
{
    cout<<"Name of Student: "<<name<<endl;
    cout<<"Student ID: "<<idnum<<endl;
    cout<<"Email Add.: "<<idnum<<"@xmu.edu.my"<<endl;
}

void Student::displayCourse()
{
    cout<<"Enrolled Courses:"<<endl;
    cout<<*this;
}

void Student::setstudentinfo()
{
    Enrol::setstudentinfo();
    name = enrolname;
    idnum = enrolid;
    Password::setpw(enrolpw);
    Courses::setCourse(idnum);
}

Student::~Student()
{
    //dtor
}
