#include "Course.h"

Course::Course() {
	courseID = -1;
	courseName = "null";
	numStudents = 0;
	students = nullptr;

}
Course::Course(const string& name, int id, int noStudents) {
	courseID = id;
	courseName = name;
	numStudents = noStudents;
	students = new string[numStudents];
}

Course::Course(const Course& temp) {
	courseID = temp.courseID;
	courseName = temp.courseName;
	numStudents = temp.numStudents;
	students = new string[numStudents];
	for (int i = 0; i < numStudents; i++) {
		students[i] = temp.students[i];
	}
}

Course::~Course() {
	delete students;
}


ostream& operator << (ostream & out, const Course & course) {
	out << "Course ID: " << course.courseID << endl; 
	out << "Course Name: " << course.courseName << endl;
	out << "Number of Enrolled Students: " << course.numStudents << endl;
	out << "Enrolled Students:" << endl;
	for (int i = 0; i < course.numStudents; ++i) {
		out << "- " << course.students[i] << endl;
	}
	cout << endl;
	return out;
}

istream& operator >> (istream& in, Course& course) {
	cout << "Enter Course ID: "  << endl;
	in >> course.courseID ;
	cout << "Enter Course Name: "  << endl;
	in >> course.courseName;
	cout << "Enter How many Students you want to Enroll: " << endl;
	in >> course.numStudents;
	course.students = new string[course.numStudents];
	for (int i = 0; i < course.numStudents; i++) {
		cout << "Enter Student's Name:  ";
		in >> course.students[i];
	}
	cout << endl;
	return in;
}



void Course::addStudent(const string& studentName) {
	numStudents++;
	string* temp = new string[numStudents];
	for (int i = 0; i < (numStudents - 1); i++) {
		temp[i] = students[i];
	}
	temp[numStudents - 1] = studentName;

	delete[] students;
	students = new string[numStudents];
	for (int i = 0; i < (numStudents); i++) {
		students[i]=temp[i];
	}
	delete[] temp;
}


string Course::getCourseName() const {
	return courseName;
}
int Course::getCourseID() const {
	return courseID;
}
int Course::getNoStudents() const {
	return numStudents;
}