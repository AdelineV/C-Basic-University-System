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

void Lecturer::setLecturer()
{
    string temppw;
    cout<<"Please enter your name:"<<endl;
    cin.ignore();
    getline(cin, this->name);
    string num = "1234567890";
    for(int i = 0; i < 7; i++)
    {
        this->idnum+=num[rand()%10];
    }
    cout<<"Please enter your new password:"<<endl;
    cin>>temppw;
    setpw(temppw);
    cout<<"ID Number: "<<this->idnum<<endl;
}

void Lecturer::setOffice()
{
    int choice;
    string course[2]={"A#", "B#"};
    string num = "1234567890";

    cout<<"Please select your faculty:"<<endl;
    cout<<"1 Faculty of Information and Communications Technology\n2 Faculty of Business"<<endl;
    cin>>choice;

    this->office += course[choice-1];
    for(int i = 0; i < 3; i++)
    {
        this->office+=num[rand()%10];
    }
    cout<<this->office<<endl;
}

void Lecturer::display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Lecturer ID: "<<idnum<<endl;
    cout<<"Email Add.: "<<idnum<<"@xmu.edu.my"<<endl;
    cout<<"Office No.: "<<office<<endl;
}

void Lecturer::displayCourse()
{
    cout<<"Courses Assigned:"<<endl;
    cout<<*this;
}

Lecturer::~Lecturer()
{
    //dtor
}
