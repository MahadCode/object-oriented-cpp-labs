#pragma once
#include<iostream>
#include<string>

using namespace std;


class Person
{
	string name;
	int age;
	float balance;
	bool employment_status;
public:
	Person();
	Person(string, int, float, bool);
	virtual void deposit(float) = 0;
	virtual void withdraw(float) = 0;
	bool isEmployed();
	void setEmploymentStatus(bool);
	void setBalance(float);
	int getBalance();

	string getName();
};

