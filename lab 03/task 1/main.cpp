#include"account.h"
#include"customer.h"
#include<iostream>
#include<string>
using namespace std;

int account::totalAccounts = 0;
double account::interestRate = 0;

int main() {
	account one(-1000);
	account two(2000);
	one.setInterestRate(5);
	two.setInterestRate(5);
	customer first("shehram",one);
	customer second("zohaib",two);
	first.display();
	second.display();
	account third(one);
	customer three("asad", third);
	one.deposit(500);
	one.withdraw(300);
	two.deposit(500);
	two.withdraw(300);
	third.deposit(500);
	third.withdraw(300);
    one.display();
}
