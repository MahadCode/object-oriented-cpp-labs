#include "Person.h"

Person::Person() {
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    while (true) {
        cin >> age;
        if (age < 0) {
            cout << "Age can't be negative! Please enter a valid age: ";
        }
        else {
            break;
        }
    }

    cin.ignore();

    cout << "Enter National ID: ";
    getline(cin, nationalID);

    cout << "Enter phone number: ";
    getline(cin, phoneNumber);

    cout << "Enter address: ";
    getline(cin, address);
}

void Person::setPersonalInfo(string n, int y, string id, string ph, string add) {
	name = n;
	age = y;
	nationalID = id;
	phoneNumber = ph;
	address = add;
}

void Person::displayPersonalInfo() {
	cout << endl;
	cout << "Person's Details" << endl;
	cout << "Name:\t" << name << endl;
	cout << "Age:\t" << age << endl;
	cout << "National ID:\t" << nationalID << endl;
	cout << "Phone Number:\t" << phoneNumber << endl;
	cout << "Address:\t" << address << endl;
}