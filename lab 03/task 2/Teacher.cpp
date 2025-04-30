#include "Teacher.h"

Teacher::Teacher() {
	name = "null";
	extensionNumber = 0;
}

Teacher::Teacher(string n, int extNum) {
	name = n;
	extensionNumber = extNum;
}

void Teacher::setName(string n) {
	name = n;
}

void Teacher::setExtensionNumber(int extNum) {
	extensionNumber = extNum;
}

string Teacher::getName() {
	return name;
}

int Teacher::getExtensionNumber() {
	return extensionNumber;
}

void Teacher::showTeacherCount(){
	cout << "Teacher Count : " << TeacherCount;
}

void Teacher::display() {
	cout << "Teacher Name " << name << endl;
	cout << "Extension Number " << extensionNumber << endl;
}