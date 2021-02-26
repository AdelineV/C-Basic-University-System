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

Password::Password()
{
    //ctor
}

void Password::setpw(string temp)
{
    pass = temp;
}

string editpw(Password &passw)
{
    string temp;
    cout<<"Please enter your new password:"<<endl;
    cin>>temp;
    cout<<"Password changed successfully!"<<endl;
    return temp;
}

string Password::getpw()
{
    return pass;
}

Password::~Password()
{
    //dtor
}
