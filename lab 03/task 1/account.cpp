#include "account.h"

account::account() {

}

account::account(double bal) {
	balance = bal;
	totalAccounts++;
}

account::account(const account& curr) {
	balance = curr.balance;
	interestRate = curr.interestRate;
	totalAccounts++;
}

//static member functions
void account::setInterestRate(double r) {
	interestRate = r;
}

double account::getInterestRate() {
	return interestRate;
}

int account::getTotalAccounts() {
	return totalAccounts;
}

//member functions
void account::deposit(double amount) {
	balance += amount;
	cout << amount << " has added:" << endl;
	cout << "Your Current Balance: " << balance << endl;
}

void account::withdraw(double amount) {
	if (amount > balance) {
		cout << "Your Current Balance is less than required amount " << endl;
	}
	else {
		balance = balance - amount;
		cout << amount << " has withdraw:" << endl;
		cout << "Your Current Balance: " << balance << endl;
	}
}

void account::display() const{
	cout << "Current Balance: " << balance << endl;
	cout << "Current Interest Rate: " << interestRate << endl;
}