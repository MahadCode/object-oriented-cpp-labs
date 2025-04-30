#ifndef FIXEDDEPOSITACCOUNT_H
#define FIXEDDEPOSITACCOUNT_H
#include<iostream>
using namespace std;
#include<string>

#include "BankAccount.h"
class FixedDepositAccount :private BankAccount
{
private:
	double depositAmount;
	int lockPeriod;
public:
	FixedDepositAccount();
	void createFD();
	void displayFixedAccount();
	friend class Admin;
};

#endif

