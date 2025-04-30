#include<iostream>
#include"Attendee.h"
#include"Speaker.h"
#include"Organizer.h"
#include<fstream>
using namespace std;

int main() {
	while (true) {
		int choice;
		cout << "1 for Speaker" << endl;
		cout << "2 for Organizer" << endl;
		cout << "3 for Attendee" << endl;
		cout << "Enter choie:" << endl;
		cin >> choice;

		if (choice == 1) {
			int id;
			cout << "Enter id" << endl;
			cin >> id;
			char* ename = new char[INT_MAX];
			cout << "Enter name" << endl;
			cin.getline(ename, '\0');
			char* email = new char[INT_MAX];
			cout << "Enter email" << endl;
			cin.getline(email, '\0');
			char* st = new char[INT_MAX];
			cout << "Enter Speaker session Topic" << endl;
			cin.getline(st, '\0');
			int sd;
			cout << "Enter Speaker session Duration" << endl;
			cin >> sd;
			Speaker s1(id, ename, email, st, sd);
			s1.performRoleTask();
			s1.displayAll();
		}

		else if (choice == 2) {
			int id;
			cout << "Enter id" << endl;
			cin >> id;
			cin.ignore();
			char* ename = new char[INT_MAX];
			cout << "Enter name" << endl;
			cin.getline(ename, '\0');
			char* email = new char[INT_MAX];
			cout << "Enter email" << endl;
			cin.getline(email, '\0');
			char* st = new char[INT_MAX];
			cout << "Enter Organizer Role" << endl;
			cin.getline(st, '\0');
			int sd;
			cout << "Enter Organizer no of event" << endl;
			cin >> sd;
			Organizer s1(id, ename, email, st, sd);
			s1.setEvents();
			s1.performRoleTask();
			s1.displayAll();
		}

		else if (choice == 3) {
			int id;
			cout << "Enter id" << endl;
			cin >> id;
			char* ename = new char[INT_MAX];
			cout << "Enter name" << endl;
			cin.getline(ename, '\0');
			char* email = new char[INT_MAX];
			cout << "Enter email" << endl;
			cin.getline(email, '\0');
			int sd;
			cout << "Enter Attendee no of event" << endl;
			cin >> sd;
			Attendee s1(id, ename, email, sd);
			s1.setSessions();
			s1.performRoleTask();
			s1.displayAll();
		}
		else {
			break;
		}
	}
}