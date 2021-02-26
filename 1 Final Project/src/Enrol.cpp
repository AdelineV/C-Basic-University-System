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

Enrol::Enrol()
{
    //ctor
}

void Enrol::setstudentinfo()
{
    int major;
    string course[5]={"CST","DMT","SWE","IBU", "ACC"};
    string num = "1234567890";

    cout<<"Please enter the name of the student: "<<endl;
    cin.ignore();
    getline(cin, this->enrolname);
    cout<<"Please select the major of the student:"<<endl;
    cout<<"1 Computer Science and Technology\n2 Digital Media and Technology\n3 Software Engineering\n4 International Business\n5 Accounting"<<endl;
    cin>>major;
    this->enrolid = course[major-1];
    for(int i = 0; i < 7; i++)
    {
        this->enrolid+=num[rand()%10];
    }
    this->enrolpw = enrolid;
    cout<<"Student account created successfully!\nStudent ID: "<<this->enrolid<<endl;
}

Enrol::~Enrol()
{
    //dtor
}
