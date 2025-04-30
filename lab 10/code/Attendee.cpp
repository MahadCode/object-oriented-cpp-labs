#include "Attendee.h"

Attendee::Attendee() : Employee() {
	noSession = 0;
	sessionDetails = nullptr;
}

Attendee::Attendee(int id,  char* n,  char* e, int ns) : Employee(id, n, e) {
	noSession = ns;
	sessionDetails = nullptr;
}

void Attendee::setSessions() {
	if (sessionDetails != nullptr) {
		for (int i = 0; i < noSession; i++) {
			delete[] sessionDetails[i];
		}
		delete[] sessionDetails;
	}
	cout << "Number of Sessions: " << noSession << endl;
	int tempNE;
	cout << "Enter new no of Session:" << endl;
	cin >> tempNE;
	noSession = tempNE;
    sessionDetails = new char* [noSession];
	for (int i = 0; i < noSession; i++) {
		cout << "Enter name of " << i + 1 << " session:" << endl;
		cin.getline(sessionDetails[i], '\0');
	}

}
void Attendee::performRoleTask() {
	displayAttendee();
}
void Attendee::displayAttendee() {
	cout << "No of Sessions:" << noSession << endl;
	for (int i = 0; i < noSession; i++) {
		cout << sessionDetails[i] << endl;
	}
	cout << endl;
}

void Attendee::displayAll() {
	displayEmp();
	displayAttendee();
}


Attendee::~Attendee() {
	if (sessionDetails != nullptr) {
		for (int i = 0; i < noSession; i++) {
			delete[] sessionDetails[i];
		}
		delete[] sessionDetails;
	}
}