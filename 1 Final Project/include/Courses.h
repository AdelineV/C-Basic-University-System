#ifndef COURSES_H
#define COURSES_H

using namespace std;

class Courses
{
protected:
public:
    vector<string> course;
    // each row represent courses for different major
    string majors[5][3] = {{"Data Structure", "C Programming", "Object-oriented Programming"},
    {"Digital Media", "Animation", "Introduction to Multimedia"},
    {"C++ Programming", "Software Fundamentals", "Fundamentals of Database"},
    {"Introduction to Business", "International Business Law", "Finance"},
    {"Introduction to Accounting", "Financial Analysis", "Accounting Principles"}};
    void setCourse(string);
    void setCourse();
    friend ostream& operator<< (ostream& os, Courses &);
    Courses();
    virtual ~Courses();
};

#endif // COURSES_H
