#include "Classroom.h"

Classroom::Classroom() {
	capacity = 0;
	roomNumber = 0;
}

Classroom::Classroom(int roNo,int cap) {
	roomNumber = roNo;
	cap = capacity;
}

void Classroom::setRoomNumber(int roNo) {
	roomNumber = roNo;
}

void Classroom::setCapacity(int cap) {
	capacity = cap;
}

void Classroom::showClassroomCount(){
	cout << "ClassRoom Count:  " << classroomCount;
}

int Classroom::getRoomNumber() {
	return roomNumber;
}

int Classroom::getCapacity() {
	return capacity;
}

void Classroom::display() {
	cout << "Capacity " << capacity << endl;
	cout << "Room Number " << roomNumber << endl;
}