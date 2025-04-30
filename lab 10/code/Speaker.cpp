#include "Speaker.h"
Speaker::Speaker() : Employee() {
	sessionTopic = new char[INT_MAX];
	sessionDuration = -1;
}
Speaker::Speaker(int id,  char* n,  char* e,  char* sn, int sd): Employee(id,n,e) {
	sessionTopic = new char[INT_MAX];
	int i = 0;
	while (n[i] != '\0') {
		sessionTopic[i] = n[i];
		i++;
	}
	sessionTopic[i] = '\0';
	sessionDuration = sd;

}

void Speaker::displaySpeaker() {
	cout << "Session Duration" << sessionDuration << endl;
	cout << "Session Topic" << sessionTopic << endl;
}

void Speaker::performRoleTask() {
	displaySpeaker();
}

void Speaker::displayAll() {
	displayEmp();
	displayEmp();
}

Speaker::~Speaker() {
	delete[] sessionTopic;
}