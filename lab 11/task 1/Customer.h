#pragma once
#include"Person.h"
class Customer: public Person
{
	float spendingPower;
public:
	Customer();
	Customer(string, int, float, bool, float);
	void makePurchase(float);
	void deposit(float) override;
	void withdraw(float) override;

};


