#include "student.h"
#include<iostream>
#include<string>
using namespace std;

student* student::allocateArray(int& sizeSt, int& sizeTest) {
    student* st = new student[sizeSt];
    for (int i = 0; i < sizeSt; i++) {
        st[i].tests = new int[sizeTest];
    }
    return st;
}

void student::getInput(student* arr, int numStudents, int numTest) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Student No " << i + 1 << endl;
        string n="";
        cout << "Enter the Student Name" << endl;
        cin >> n;
        arr[i].name = n;

        int d=0;
        cout << "Enter the Sudent Id" << endl;
        cin >> d;
        arr[i].idNumber = d;

        for (int j = 0; j < numTest; j++) {
            int cur;
            cout << "Enter the Test No " << j+1 << " score: ";
            cin >> cur;
            arr[i].tests[j] = cur;
        }
        cout << endl << endl;
    }
}

void student::calcAvgAndGrade(student* arr, int numStudents, int numTests) {
    for (int i = 0; i < numStudents; i++) {
        double sum = 0;
        for (int j = 0; j < numTests; j++) {
            sum = sum + arr[i].tests[j];
        }
        arr[i].average = sum / numTests;
        if (arr[i].average >= 90) {
            arr[i].grade = 'A';
        }
        else if (arr[i].average >= 80 && arr[i].average < 90) {
            arr[i].grade = 'B';
        }
        else if (arr[i].average >= 70 && arr[i].average < 80) {
            arr[i].grade = 'C';
        }
        else if (arr[i].average >= 60 && arr[i].average < 70) {
            arr[i].grade = 'D';
        }
        else if (arr[i].average >= 50 && arr[i].average < 60) {
            arr[i].grade = 'E';
        }
        else {
            arr[i].grade = 'F';
        }
    }

}

void student::displayOneStudent(const student& st, int numTest) {
    cout << "Student's Name:" << endl;
    cout << st.name <<endl;
    cout << "Student's IDNumber:" << endl;
    cout << st.idNumber << endl;
    for (int i = 0; i < numTest; i++) {
        cout << "Test No. " << i + 1 << "Score: ";
        cout << st.tests[i] << endl;
    }
    cout << "Student's Average: " << endl;
    cout << st.average << endl;
    cout << "Student's Grade: " << endl;
    cout << st.grade << endl << endl << endl;
}

void student::displayStudents(student* arr, int numStudents, int numTests) {
    for (int i = 0; i < numStudents; i++) {
        arr[i].displayOneStudent(arr[i], numTests);
    }
}

int student::getStudentCount(student* arr, int numStudents, char grade) {
    int count = 0;
    for (int i = 0; i < numStudents; i++) {
        if (arr[i].grade == grade) {
            count++;
        }
    }
    return count;
}

student* student::getBestStudent(student* arr, int numStudents) {
    student* best=NULL;
    double mxavg=0;
    for (int i = 0; i < numStudents; i++) {
        if (arr[i].average > mxavg) {
            mxavg = arr[i].average;
            best = (arr+i);
        } 
    }
    return best;
}
void student::displayBestStudent(student* arr, int numStudents, int numTests) {
    student* best = getBestStudent(arr, numStudents);
    displayOneStudent(*best, numTests);
}

void  student::dellocateArray(student*& arr, int numStudents, int numTests) {
    for (int i = 0; i < numStudents; i++) {
        delete[] arr[i].tests;
    }
    delete[] arr;
    arr = nullptr;
}
