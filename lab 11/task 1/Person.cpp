#include "Person.h"

Person::Person() {
	name = "Null";
	age = -1;
	balance = -1;
	employment_status = false;

}

Person::Person(string n, int a, float b, bool s) {
	name = n;
	age = a;
	balance = b;
	employment_status = s;
}

bool Person::isEmployed() {
	return employment_status;
}

void Person::setEmploymentStatus(bool status) {
	employment_status = status;
}

void Person::setBalance(float b) {
	balance = b;
}

 int Person::getBalance() {
	return balance;
}

 string Person::getName() {
	 return name;
 }