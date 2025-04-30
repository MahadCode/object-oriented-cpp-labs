#include"student.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
    student x;
    int s = 0;
    int b = 0;
    cout << "Enter the Number of Students: " << endl;
    cin >> s;
    cout << "Enter the Number of Tests for each Student: " << endl;
    cin >> b;
    student* arr;
    arr=x.allocateArray(s, b);
    x.getInput(arr, s, b);
    x.calcAvgAndGrade(arr, s, b);
    //for (int i = 0; i < s; i++) {
    //    x.displayOneStudent(arr[i], b);
    //} 
    x.displayStudents(arr, s, b);

    x.displayBestStudent(arr, s, b);

    char cur = 65;
    for (int i = 0; i < 6; i++) {
        cout << "No of Students which have obtained " << cur << endl;
        cout << x.getStudentCount(arr, s, cur) << endl;
        cur++;
    }

    x.dellocateArray(arr, s, b);

}