#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include<iostream>
using namespace std;
#include<string>

#include "BankAccount.h"
class SavingAccount :
    protected BankAccount
{
private:
    double interestRate;
public:
    SavingAccount();
    void calculateInterest();
    friend class Admin;
};

#endif
