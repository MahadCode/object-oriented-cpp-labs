#include "Department.h"
Department::Department() {
    departmentName="null";
    courses=nullptr;
    numCourses=0;
    currCourses = 0;
}
Department::Department(string name, int nC) {
    departmentName = name;
    numCourses = nC;
    courses = new Course[numCourses];
    currCourses = 0;
}

Department::Department(const Department& temp) {
    departmentName = temp.departmentName;
    numCourses = temp.numCourses;
    courses = new Course[numCourses];
    for (int i = 0; i < numCourses; i++) {
        courses[i] = temp.courses[i];
    }
}

Department::~Department() {
    delete[] courses;
}

void Department::setDept(string name, int nC) {
    departmentName = name;
    numCourses = nC;
    courses = new Course[numCourses];
    currCourses = 0;
}

bool Department::operator<(const Department& temp) const {
    return (numCourses < temp.numCourses);
}
bool Department::operator>(const Department& temp) const {
    return (numCourses > temp.numCourses);
}
bool Department::operator==(const Department& temp) const {
    return (numCourses == temp.numCourses);
}

ostream& operator<<(ostream& out, const Department& dept) {
    out << "Department Name: " << dept.departmentName << endl;
    out << "Number of Courses" << dept.numCourses << endl;
    out << "Courses:" << endl;
    for (int i = 0; i < dept.numCourses; ++i) {
        out << "- " << dept.courses[i] << endl;
    }
    return out;
}

void Department::addCourse(const Course& course) {
    courses[currCourses] = course;
    currCourses++;
}

string Department::getDeptName() const {
    return departmentName;
}

int Department::getNumCourses() const {
    return numCourses;
}

