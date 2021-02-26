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
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, Courses &c1)
{
    vector<string>::iterator it;
    int i;

    for(it=c1.course.begin(), i=1;it!=c1.course.end();it++, i++)
    {
        os<<i<<" "<<*it<<endl;
    }

    return os;
}

void Courses::setCourse()
{
    int flag = 1;
    int major, j;

    while(flag)
    {
        cout<<"Please select the majors you teach:"<<endl;
        cout<<"1 Computer Science and Technology\n2 Digital Media and Technology\n3 Software Engineering\n4 International Business\n5 Accounting"<<endl;
        cout<<"Press (0) to exit."<<endl;
        cin>>major;

        if(major == 1)
        {
            for(j=0;j<3;j++)
                course.push_back(majors[major-1][j]);
        }
        else if(major == 2)
        {
            for(j=0;j<3;j++)
                course.push_back(majors[major-1][j]);
        }
        else if(major == 3)
        {
            for(j=0;j<3;j++)
                course.push_back(majors[major-1][j]);
        }
        else if(major == 4)
        {
            for(j=0;j<3;j++)
                course.push_back(majors[major-1][j]);
        }
        else if(major == 5)
        {
            for(j=0;j<3;j++)
                course.push_back(majors[major-1][j]);
        }
        else
            flag = 0;
    }
}

void Courses::setCourse(string temp) //when enrol we need to input the student id
{
    int j;
    string test = temp.substr(0,3);
    if(test == "CST")
    {
        for(j=0;j<3;j++)
            course.push_back(majors[0][j]);
    }
    else if(test == "DMT")
    {
        for(j=0;j<3;j++)
            course.push_back(majors[1][j]);
    }
    else if(test == "SWE")
    {
        for(j=0;j<3;j++)
            course.push_back(majors[2][j]);
    }
    else if(test == "IBU")
    {
        for(j=0;j<3;j++)
            course.push_back(majors[3][j]);
    }
    else if(test == "ACC")
    {
        for(j=0;j<3;j++)
            course.push_back(majors[4][j]);
    }
}

Courses::Courses()
{
    //ctor
}

Courses::~Courses()
{
    //dtor
}
