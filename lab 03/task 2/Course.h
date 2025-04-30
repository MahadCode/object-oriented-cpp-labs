#pragma once
#include"Teacher.h"
#include"Classroom.h"
#include<iostream>
#include<string>
using namespace std;

class Course
{
	string courseTitle;
	Teacher teacher;
	Classroom classroom;
	static int CourseCount;
    public:
		Course();
		Course(string, string, int, int, int);
		void display();
		void setCourseTitel(string);
		void setTeacher(Teacher);
		void setClassroom(Classroom);

		static void showCourseCount();
};

