#include "Customer.h"

Customer::Customer(string name, int age, float balance, bool status, float Power) : Person(name, age, balance, status) {
	spendingPower=Power;

}

void Customer::makePurchase(float amount) {
	withdraw(amount);
}
void Customer::deposit(float amount) {
	float curr = getBalance() + amount;
	setBalance(curr);
}
void Customer::withdraw(float amount) {
float curr = getBalance() - amount;
	setBalance(curr);
}