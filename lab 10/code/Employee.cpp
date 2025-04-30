#include "Employee.h"
Employee::Employee() {
	empID = -1;
	name = new char[INT_MAX];
	email = new char[INT_MAX];
};

Employee::Employee(int id, char* n,char* e) {
	empID = id;
	name = new char[INT_MAX];
	email = new char[INT_MAX];
	int i = 0;
	while (n[i] != '\0') {
		name[i] = n[i];
		i++;
	}
	name[i] = '\0';
	
	i = 0;
	while (e[i] != '\0') {
		email[i] = e[i];
		i++;
	}
	email[i] = '\0';
}

void Employee::displayEmp() {
	cout << "Employee's ID:\t" << empID << endl;
	cout << "Employee's Name:\t" << name << endl;
	cout << "Employee's Email:\t" << email << endl;
	cout << endl;
}

Employee::~Employee() {
	delete[] name;
	delete[] email;
}

void Employee::setEmp(int id, char* n, char* e) {
	empID = id;
	int i = 0;
	while (n[i] != '\0') {
		name[i] = n[i];
		i++;
	}
	name[i] = '\0';

	i = 0;
	while (e[i] != '\0') {
		email[i] = e[i];
		i++;
	}
	email[i] = '\0';
}