#include "FixedDepositAccount.h"

FixedDepositAccount::FixedDepositAccount() : BankAccount() {
    createFD();
}

void FixedDepositAccount::createFD() {
    cout << "Enter Deposit Amount(can't greater than balance):" << endl;
    cin >> depositAmount;
    do {
        cin >> depositAmount;
    } while (depositAmount>balance);
     
    cout << "Enter period" << endl;
    do {
        cin >> lockPeriod;
    } while (lockPeriod<1); 
}

void FixedDepositAccount::displayFixedAccount() {
    displayAccountDetails();
}