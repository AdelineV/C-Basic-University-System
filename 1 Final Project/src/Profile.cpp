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

Profile::Profile()
{
    //ctor
}

string Profile::getname()
{
    return name;
}

string Profile::getidnum()
{
    return idnum;
}

Profile::~Profile()
{
//    check if vector of pointers are deleted:
//    cout<<"Destructor"<<endl;
}
