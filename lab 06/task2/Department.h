#pragma once
#include<iostream>
#include<string>
#include"Course.h"

using namespace std;

class Department
{
    string departmentName;
    Course* courses;          
    int numCourses;
    int currCourses;
public:
    Department();
    Department(string name, int numCourses);
    Department(const Department& other);
    ~Department();

    void setDept(string, int);
    string getDeptName() const;
    int getNumCourses() const;

    void addCourse(const Course& course);
    bool operator<(const Department&) const;
    bool operator>(const Department&) const;
    bool operator==(const Department&) const;

    friend ostream& operator<<(ostream& os, const Department& dept);
};


