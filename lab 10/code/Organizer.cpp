#include "Organizer.h"
Organizer::Organizer() : Employee() {
	role = new char[INT_MAX];
	noEvents = 0;
	eventDetails = nullptr;
}
Organizer::Organizer(int id,  char* n,  char* e,  char* r, int ne) : Employee(id, n, e) {
	role = new char[INT_MAX];
	int i = 0;
	while (r[i] != '\0') {
		role[i] = n[i];
		i++;
	}
	role[i] = '\0';
	noEvents = ne;
	eventDetails = nullptr;
}

void Organizer::setEvents() {
	if (eventDetails != nullptr) {
		for (int i = 0; i < noEvents; i++) {
			delete[] eventDetails[i];
		}
		delete[] eventDetails;
	}
	cout << "Number of Events: " << noEvents << endl;
	int tempNE;
	cout << "Enter new no of events:" << endl;
	cin >> tempNE;
	noEvents = tempNE;
	eventDetails = new char*[noEvents];
	for(int i = 0; i < noEvents; i++) {
		cout << "Enter name of " << i + 1 << " event:" << endl;
		cin.getline(eventDetails[i], '\0');
	}

}
void Organizer::performRoleTask() {
	displayOrganizer();
}
void Organizer::displayOrganizer() {
	cout << "Organizer Role:" << role << endl;
	cout << "No of Events:"<< noEvents << endl;
	for (int i = 0; i < noEvents; i++) {
		cout << eventDetails[i] << endl;
	}
	cout << endl;
}

void Organizer::displayAll() {
	displayEmp();
	displayOrganizer();
}


Organizer::~Organizer() {
	if (eventDetails != nullptr) {
		for (int i = 0; i < noEvents; i++) {
			delete[] eventDetails[i];
		}
		delete[] eventDetails;
	}
}