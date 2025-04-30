#pragma once
#include<iostream>
using namespace std;

class Employee
{
	int empID;
	char* name;
	char* email;
public:
	Employee();
	Employee(int,char*,char*);
	virtual void performRoleTask() = 0;
	void displayEmp();
	void setEmp(int,char*,char*);
	~Employee();
};

