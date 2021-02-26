#ifndef PASSWORD_H
#define PASSWORD_H

using namespace std;

class Password
{
private:
    string pass;
public:
    Password();
    void setpw(string);
    friend string editpw(Password &);
    string getpw();
    virtual ~Password();
};

#endif // PASSWORD_H
