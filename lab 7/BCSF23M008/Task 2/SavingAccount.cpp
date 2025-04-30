#include "SavingAccount.h"
SavingAccount::SavingAccount(): BankAccount() {
	cout << "Enter interest Rate" << endl;
		cin >> interestRate;
		do {
			cin >> interestRate;
		} while (interestRate < 1);
	calculateInterest();
}
void SavingAccount::calculateInterest() {
	
}