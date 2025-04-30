#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;

class Company
{
	string name;
	float revenue;
	Employee** employees;
	float profitMargin;
	int noEmployee;
	
public:
	Company();
	Company(string,float);
	void hireEmployees(Employee&);
	void fireEmployees(Employee&);
	void payEmployee();
	void generateRevenue();
	void distributeProfit();

};

