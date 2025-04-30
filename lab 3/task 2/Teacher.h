#pragma once
#include<iostream>
#include<string>
using namespace std;


class Teacher
{
	string name;
	int extensionNumber;
	static int TeacherCount;
    public:
		Teacher();
		Teacher(string, int);
		void display();
		void setName(string);
		void setExtensionNumber(int);
		string getName();
		int getExtensionNumber();
		static void showTeacherCount();
};

