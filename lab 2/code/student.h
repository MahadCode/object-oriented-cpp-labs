#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class student
{
    string name;
    int idNumber;
    int* tests;
    double average;
    char grade;
public:
    student* allocateArray(int&, int&);
    void getInput(student*, int, int);
    void calcAvgAndGrade(student*, int, int);
    void displayOneStudent(const student&, int);
    void displayStudents(student*, int, int);
    int getStudentCount(student* , int, char);
    student* getBestStudent(student* , int);
    void displayBestStudent(student*, int, int);
    void dellocateArray(student*& , int, int);
};

