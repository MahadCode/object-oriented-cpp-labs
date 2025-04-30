#include "Bank.h"

Bank::Bank() {
	accounts = nullptr;
	name = "NUll";
	interestRate = 0;
	noPerson = 0;

}
Bank::Bank(string n, float iR) {
	name = n;
	interestRate = iR;
	accounts = new Person * [10000];
	noPerson = 0;
}

void Bank::openAccount(Person& person) {
	Person* temp = new Person[noPerson];
	for (int i = 0; i < ; i++) {

	}
}
void Bank::closeAccount(Person& person) {

}
void Bank::applyInterest() {

}