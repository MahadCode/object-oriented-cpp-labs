#include "Company.h"
Company::Company() {
	name = "null";
	revenue = 0;
	profitMargin = 0;
	noEmployee = 0;
	employees = new Employee * [1000];

}

Company::Company(string n, float m) {
	name = n;
	noEmployee = 0;
	profitMargin = m;
	employees = new Employee * [1000];
}

void Company::hireEmployees(Employee& coming) {
	noEmployee++;
	employees[noEmployee] = &coming;
}

void Company::fireEmployees(Employee& going) {
	for (int i = 0; i < noEmployee; i++) {
		if (employees[i]->getName() == going.getName()) {
			employees[i]->setEmploymentStatus(false);
		}
	}
}

void Company::payEmployee() {
	for (int i = 0; i < noEmployee; i++) {
		employees[i]->receiveSalary();
	}
}

void Company::generateRevenue() {
	float temp = 0;
	for (int i = 0; i < noEmployee; i++) {
		temp = temp + (0.2 * employees[i]->getSalary());
	}
	revenue = temp;
}

void Company::distributeProfit() {
	for (int i = 0; i < noEmployee; i++) {
		float profitMarginEmployee = profitMargin / noEmployee;
		float newSal = employees[i]->getSalary() + profitMarginEmployee;
		employees[i]->setSalary(newSal);
	}
}