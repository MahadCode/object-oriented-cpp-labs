#include"Classroom.h"
#include"Teacher.h"
#include"Course.h"
#include<iostream>
#include<string>
using namespace std;

int Classroom::classroomCount = 0;
int Teacher::TeacherCount = 0;
int Course::CourseCount = 0;

int main() {
	Course first("Data", "sir1", 2, 5, 40);
	Course second("asdf", "si2", 6, 9, 30);

	

	string c;
	do {
		cout << "Enter course name" << endl;
		cin >> c;
	} while (c.size() > 30);

	string n;
	do {
		cout << "Enter Teacher name" << endl;
		cin >> n;
	} while (n.size() > 40);
	int extNo;
	cout << "Enter Extern number" << endl;
	cin >> extNo;
	int roNo;
	cout << "Enter room number " << endl;
	cin >> roNo;
	int cap;
	cout << "Enter the capacity " << endl;
	cin >> cap;
	Course againFirst(c, n, extNo, roNo, cap);

	string c1;
	do {
		cout << "Enter course name" << endl;
		cin >> c1;
	} while (c1.size() > 30);

	string n1;
	do {
		cout << "Enter Teacher name" << endl;
		cin >> n1;
	} while (n1.size() > 40);
	int extNo1;
	cout << "Enter Extern number" << endl;
	cin >> extNo1;
	int roNo1;
	cout << "Enter room number " << endl;
	cin >> roNo1;
	int cap1;
	cout << "Enter the capacity " << endl;
	cin >> cap1;
	Course* x = new Course;
	Teacher tempt(n1, extNo1);
	Classroom tempc(roNo1, cap1);
	x->setCourseTitel(c1);
	x->setClassroom(tempc);
	x->setTeacher(tempt);


	first.display();
	second.display();
	againFirst.display();
	x->display();

		
	}