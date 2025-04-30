#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<iostream>
using namespace std;
#include<string>

#include "Person.h"
class BankAccount : public Person
{
protected:
	string accountNumber;
	double balance;
	double minimumBalance;
public:
	BankAccount();
	void deposit();
	void withdraw();
	void displayAccountDetails();
};

#endif

