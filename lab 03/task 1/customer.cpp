#include "customer.h"

customer::customer(string n, account acont){
	name = n;
	Account = acont;
}

void customer::display() const{
	cout << "Customer Name: " << name << endl;
	Account.display();
}