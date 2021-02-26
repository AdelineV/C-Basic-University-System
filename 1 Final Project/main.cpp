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

int findIndex(vector<string> userID, vector<string> passwords)
{
    int index = 0;
    string temp, temppw;
    vector<string>::iterator it1;
    vector<string>::iterator it2 = passwords.begin();

    cout<<"Please enter your ID:"<<endl;
    cin>>temp;
    cout<<"Please enter your password:"<<endl;
    cin>>temppw;

    for(it1=userID.begin(); it1!=userID.end(); it1++)
    {
        if(*it1 == temp)
        {
            if(*(it2+index) == temppw)
                return index;
            else
            {
                cout<<"Password Incorrect!"<<endl<<endl;
                return -1;
            }
        }
        index++;
    }
    if(index >= userID.size())
    {
        cout<<"Invalid User ID!"<<endl<<endl;
        return -1;
    }
}

int adminMenu(vector<Profile*> &profile, vector<string> &userID, vector<string> &passwords, int index)
{
    int choice, major;
    string temp;
    cout<<"\n=================MENU:================="<<endl;
    cout<<"1 Display Basic Information\n2 Enrol a New Student\n3 Change Password\n4 Logout"<<endl;
    cout<<"========================================"<<endl;
    cin>>choice;
    if(choice == 1)
    {
        profile[index]->display();
        cout<<"========================================"<<endl;
        return 1;
    }
    else if(choice == 2)
    {
        Profile *student = dynamic_cast<Profile*>(new Student);
        profile.push_back(student);
        userID.push_back(profile.at(profile.size()-1)->getidnum());
        passwords.push_back(profile.at(profile.size()-1)->getpw());
//        cout<<"PROFILE: "<<profile.size()<<endl;
//        cout<<"ID: "<<userID.size()<<endl;
//        cout<<"PW: "<<passwords.size()<<endl;
        return 1;
    }
    else if(choice == 3)
    {
        Password pw;
        string temp = editpw(pw);
        passwords[index] = temp;
        return 1;
    }
        return -1;
}

int lecturerMenu(vector<Profile*> &profile, vector<string> &passwords, int index)
{
    int choice;
    cout<<"\n=================MENU:================="<<endl;
    cout<<"1 Display Basic Information\n2 View Assigned Classes\n3 Change Password\n4 Logout"<<endl;
    cout<<"========================================"<<endl;
    cin>>choice;
    if(choice == 1)
    {
        profile[index]->display();
        cout<<"========================================"<<endl;
        return 1;
    }
    else if(choice == 2)
    {
        profile[index]->displayCourse();
        cout<<"========================================"<<endl;
        return 1;
    }
    else if(choice == 3)
    {
        Password pw;
        string temp = editpw(pw);
        passwords[index] = temp;
        return 1;
    }
    else
        return -1;
}

int studentMenu(vector<Profile*> &profile, vector<string> &passwords, int index)
{
    int choice;

    cout<<"\n=================MENU:================="<<endl;
    cout<<"1 Display Basic Information\n2 Display Courses Enrolled\n3 Change Password\n4 Logout"<<endl;
    cout<<"========================================"<<endl;
    cin>>choice;
    if(choice == 1)
    {
        profile[index]->display();
        cout<<"========================================"<<endl;
        return 1;
    }
    else if(choice == 2)
    {
        profile[index]->displayCourse();
        cout<<"========================================"<<endl;
        return 1;
    }
    else if(choice == 3)
    {
        Password pw;
        string temp = editpw(pw);
        passwords[index] = temp;
        return 1;
    }
    else
        return -1;
}

int login(vector<Profile*> &profile, vector<string> &userID, vector<string> &passwords)
{
    int staff, role, verif;
    string temp, password;

    cout<<"XIAMEN UNIVERSITY MALAYSIA"<<endl;
    cout<<"========================================"<<endl;
    cout<<"Please select your identity:"<<endl;
    cout<<"1 Admin\n2 Lecturer\n3 Student\nPress (0) to exit."<<endl;
    cin>>role;
    if(role == 1) // ADMINISTRATOR LOGIN //
    {
        cout<<"Please select:\n1 Existing Administrator\n2 New Administrator"<<endl;
        cin>>staff;

        if(staff == 1)
        {
            return 1;
        }
        else if(staff == 2)
        {
            Profile *admin = static_cast<Profile*>(new Admin);
            profile.push_back(admin);
            userID.push_back(profile.at(profile.size()-1)->getidnum());
            passwords.push_back(profile.at(profile.size()-1)->getpw());
            return 1;
        }
        else
            return -1;
    }
    if(role == 2) // LECTURER LOGIN //
    {
        cout<<"Please select:\n1 Existing Lecturer\n2 New Lecturer"<<endl;
        cin>>staff;
        if(staff == 1)
        {
            return 2;
        }
        else if(staff == 2)
        {
//            register new lecturer
            //Lecturer lecturer(1);
            profile.push_back(new Lecturer);
            //setOffice(lecturer);
            userID.push_back(profile.at(profile.size()-1)->getidnum());
            passwords.push_back(profile.at(profile.size()-1)->getpw());
            cout<<"Lecturer account created successfully!"<<endl;
            return 2;
        }
        else
            return -1;
    }
    else if(role == 3) // STUDENT LOGIN //
    {
        return 3;
    }
    else if(role == 0)
        return 0;
    else
        return -1;
}

int main()
{
    vector<Profile*> profile;
    vector<string> userID;
    vector<string> passwords;

    int index;
    int flag1 = -1;
    int flag2 = -1;

    while(flag1 == -1 || flag2 == -1)
    {
        flag1 = -1;
        flag1 = login(profile, userID, passwords);
        if(flag1 == 1)
        {
            flag2 = 1;
            index = findIndex(userID, passwords);
            if(index == -1)
                flag2 = -1;
            while(flag2 == 1)
            {
                flag2 = adminMenu(profile, userID, passwords, index);
            }
        }
        else if(flag1 == 2)
        {
            flag2 = 1;
            index = findIndex(userID, passwords);
            if(index == -1)
                flag2 = -1;
            while(flag2 == 1)
                flag2 = lecturerMenu(profile, passwords, index);
        }
        else if(flag1 == 3)
        {
            flag2 = 1;
            index = findIndex(userID, passwords);
            if(index == -1)
                flag2 = -1;
            while(flag2 == 1)
                flag2 = studentMenu(profile, passwords, index);
        }
        else if(flag1 == -1)
            continue;
        else
        {
            flag1 = 1;
            flag2 = 1;
            for(int i=0;i<profile.size();i++)
            {
                delete profile[i];
                profile[i] = NULL;
            }
            profile.clear();
//            cout<<"Profile vector size: "<<profile.size()<<endl;
//            cout<<"Profile vector capacity: "<<profile.capacity()<<endl;
        }
    }

    return 0;
}
