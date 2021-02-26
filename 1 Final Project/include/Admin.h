#ifndef ADMIN_H
#define ADMIN_H

#include <Courses.h>
#include <Profile.h>
#include <Enrol.h>

class Admin : public Profile, public Enrol
{
private:

public:
    void setAdmin();
    void display();
    Admin()
    {
        setAdmin();
    }
    virtual ~Admin(){}
};

#endif // ADMIN_H
