#include "Employee.h"

Employee::Employee():Person() {

}

Employee::Employee(string name, int age, float balance, bool status, float salary, string comName) : Person(name, age, balance, status) {
	this->salary= salary;
	companyName = comName;
}
void Employee::receiveSalary() {
	deposit(salary);
}
void Employee::work() {
	cout << "Employee " << getName() << "has done the work" << endl;
}

void Employee::deposit(float amount) {
	float curr = getBalance() + amount;
	setBalance(curr);
}
void Employee::withdraw(float amount) {
	float curr = getBalance() - amount;
	setBalance(curr);
}

void Employee::setSalary(float a) {
	salary = a;
}
float Employee::getSalary() {
	return salary;
}

