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

void Admin::setAdmin()
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

void Admin::display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Admin ID: "<<idnum<<endl;
    cout<<"Email Add.: "<<idnum<<"@xmu.edu.my"<<endl;
}
