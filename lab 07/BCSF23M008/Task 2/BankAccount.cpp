#include "BankAccount.h"

BankAccount::BankAccount() : Person() {
	cout << "Enter account number: " << endl;;
	getline(cin, accountNumber);

	cout << "Enter balance: " << endl;
	while (true) {
		cin >> balance;
		if (balance < 0) {
			cout << "Balance can't be negative! Please enter a valid balance: ";
		}
		else {
			break;
		}
	}

	cout << "Enter minimum balance: ";
	while (true) {
		cin >> minimumBalance;
		if (minimumBalance < 0) {
			cout << "Minimum balance can't be negative! Please enter a valid minimum balance: ";
		}
		else if (minimumBalance > balance) {
			cout << "Minimum balance can't be be greater than balance! Please enter a valid minimum balance: ";
		}
		else {
			break;
		}
	}

	cin.ignore();
	
}

void BankAccount::deposit() {
	cout << "Enter amount to add" << endl;
	int temp;
	do {
		cin >> temp;
	} while (temp < 1);
	balance += temp;
	cout << "Transaction has performed" << endl;
}
void BankAccount::withdraw() {
	cout << "Enter amount to withdraw" << endl;
	int temp;
	while (true) {
		cin >> temp;

		if (balance - temp >= minimumBalance) {
			balance -= temp;
			cout << "Transaction has performed" << endl;
			break;

		}
		else {
			cout << "After withdraw, balance is decreased than minimum balance " << endl;
			cout << "Transaction can't be performed" << endl;
		}

	}
}
void BankAccount::displayAccountDetails() {
	displayPersonalInfo();
	cout << endl << "Account Details" << endl;
	cout << "Account Number:\t" << accountNumber << endl; 
	cout << "Balance:\t" << balance << endl;
	cout << "Minimum Balance:\t" << minimumBalance << endl;
}