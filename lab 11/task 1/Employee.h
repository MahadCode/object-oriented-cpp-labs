#pragma once
#include"Person.h"
class Employee
	: public Person
{
	float salary;
	string companyName;

public:
	Employee();
	Employee(string, int, float, bool, float, string);
	void receiveSalary();
	void work();

	void deposit(float) override;
	void withdraw(float) override;

	void setSalary(float);
	float getSalary();

};

