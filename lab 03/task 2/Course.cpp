#include "Course.h"

Course::Course() {
	courseTitle = "null";
}

Course::Course(string crsT, string n, int extNum, int roNo, int cap) {
	courseTitle = crsT;
	teacher.setName(n);
	teacher.setExtensionNumber(extNum);
	classroom.setRoomNumber(roNo);
	classroom.setCapacity(cap);
}



void Course::showCourseCount(){
	cout << "Course Count: " << CourseCount;
}

void Course::setCourseTitel(string n) {
	courseTitle = n;

}
void Course::setTeacher(Teacher t) {
	teacher = t;
}

void Course::setClassroom(Classroom c) {
	classroom = c;
}

void Course::display(){
	cout << "Course Title " << courseTitle << endl;
	teacher.display();
	classroom.display();
}