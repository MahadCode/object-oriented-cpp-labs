#include "Product.h"

void checkError(int n) {
	string err = "Can't be negative";
	if (n <= 0) {
		throw err;
    }
}

Product::Product() {
	productID = -1;
	name = "null";
	quantity = 0;
	price = -1;
}
Product::Product(int id, string n) {
	productID = id;
	name = n;
	quantity = 0;
	price = -1;
}
void Product::updateDetails() {
	cout << "ProductID: " << productID << endl;
	cout << "Enter the name:" << endl;
	cin >> name;
	while (true) {
		try {
			cout << "Enter the quantity: " << endl;
			cin >> quantity;
			checkError(quantity);
			break;
	    }
		catch(string e){
			cout << e << endl;
		}
	}
	while (true) {
		try {
			cout << "Enter the price: " << endl;
			cin >> price;
			checkError(quantity);
			break;
		}
		catch (string e) {
			cout << e << endl;
		}
	}
	
	
}

void Product::addStock(int s) {
	quantity += s;
}

void Product::removeStock(int s) {
	int req = s;
	while(true){
		try {
			checkAvailability(req);
			break;
		}
		catch (string err) {
			cout << err << endl;
			cout << "Again enter stock: ";
			cin >> req;
		}
	}
}

void Product::checkAvailability(int q){
	
	if (quantity - q >= 0) {
	}
	else {
		string err = "Required Quantity don't exists";
		throw err;
	}
}

void Product::displayDetail() {
	cout << "Product Id: " << productID << endl;
	cout << "Product Name: " << name << endl;
	cout << "Product Quantity: " << quantity << endl;
	cout << "Product Price:" << price << endl;
}

int Product::getID() {
	return productID;
}

void Product::saveFile(ostream& ou) {
	ou << productID << name << quantity << price << endl;
}

void Product::loadFile(istream& in) {
	in >> productID >> name >> quantity >> price;
}

