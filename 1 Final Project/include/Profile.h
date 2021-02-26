#ifndef PROFILE_H
#define PROFILE_H

#include <Password.h>

class Profile : public virtual Password
{
private:
protected:
    string name;
    string idnum;
public:
    string getname();
    string getidnum();
    void setUser();
    int findIndex();
    virtual void display()=0;
    virtual void displayCourse(){}
    Profile();
    virtual ~Profile();
};

#endif // PROFILE_H
