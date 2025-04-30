#pragma once
#include<iostream>
#include<string>
using namespace std;

class Course
{
    string courseName;
    int courseID;
    string* students;    
    int numStudents;
public:
    
    Course();
    Course(const string&, int , int );
    Course(const Course&);
    ~Course();

  
    friend ostream& operator << (ostream&, const Course&);
    friend istream& operator >> (istream&,Course&);


   
    void addStudent(const string& studentName);

    
    string getCourseName() const;
    int getCourseID() const;
    int getNoStudents() const;
};

