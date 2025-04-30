#pragma once
#include<iostream>
#include<string>
using namespace std;

class account
{
	double balance;
	static double interestRate;
	static int totalAccounts;
    public:
		account();
		account(double);
		account(const account&);
		static void setInterestRate(double);
		static double getInterestRate();
		static int getTotalAccounts();
		void deposit(double amount); // Adds the specified amount to the balance.
		void withdraw(double amount); // Subtracts the specified amount from the balance, ensuring that the balancedoes not go negative.If amount is greater than the balance, print an appropriate message.
		void display() const;
	    // const : Displays the balance and the current interest rate.


};

