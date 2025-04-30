#pragma once
#include<iostream>
#include"Person.h"
using namespace std;

class Bank
{
	string name;
	Person** accounts;
	float interestRate;
	int noPerson;
public:
	Bank();
	Bank(string, float);
	void openAccount(Person& person);
	void closeAccount(Person& person);
	void applyInterest();
};

