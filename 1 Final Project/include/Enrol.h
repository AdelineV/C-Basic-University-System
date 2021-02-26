#ifndef ENROL_H
#define ENROL_H


class Enrol : public virtual Password
{
protected:
    string enrolname;
    string enrolid;
    string enrolpw;
public:
    virtual void setstudentinfo();
    Enrol();
    virtual ~Enrol();
};

#endif // ENROL_H
