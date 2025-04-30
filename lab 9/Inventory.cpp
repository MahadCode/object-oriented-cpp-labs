#include "Inventory.h"

void checkFile(ostream& file) {
	string err = "File not open";
	if (file) {

	}
	else {
		throw err;
	}
}

void checkFile1(istream& file) {
	string err = "File not open";
	if (file) {

	}
	else {
		throw err;
	}
}

Inventory::Inventory() {
	size = 0;
	capacity = 10000;
	products = new Product*[capacity];
}

void Inventory::addProduct(Product& temp) {
	try {
		checkAvailability(temp.getID());
		products[size] = &temp;
		size++;
	}
	catch (string  e) {
		cout << e << endl;
	}

}

void Inventory::removeProduct(Product& temp) {
	try {
		int req = temp.getID();
		checkAvailability(temp.getID());
		int noMatch = 0;
		for (int i = 0; i < size; i++) {
			if (products[i]->getID() == req) {
				noMatch++;
			}
		}
		int tempSize = size-noMatch;
		Product** tempProducts = new Product * [tempSize];

		int index=0;
		for (int i = 0; i < size; i++) {
			if (products[i]->getID() == req) {
				continue;
			}
			tempProducts[index] == products[i];
			index++;
		}

		for (int i = 0; i < size; i++) {
			delete products[i];
		}

		size = tempSize;
		for (int i = 0; i < size; i++) {
			products[i] = tempProducts[i];
		}

		delete[] tempProducts;
	}
	catch (string  e) {
		cout << e << endl;
	}

}

void Inventory::checkAvailability(int id) {
	int status = false;
	for (int i = 0; i < size; i++) {
		if (id == products[i]->getID()) {
			status=true;
		}
	}
	if (!status) {
		string eror = "Product don't found";
		throw eror;
	}
}

void Inventory::addStock(Product& temp,int amount) {
	try {
		int req = temp.getID();
		checkAvailability(req);
		for (int i = 0; i < size; i++) {
			if (products[i]->getID() == req) {
				products[i]->addStock(amount);
			}
		}

	}
	catch(string e){
		cout << e << endl;
	}
}

void Inventory::removeStock(Product& temp, int amount) {
	try {
		int req = temp.getID();
		checkAvailability(req);
		for (int i = 0; i < size; i++) {
			if (products[i]->getID() == req) {
				products[i]->addStock(amount);
			}
		}

	}
	catch (string e) {
		cout << e << endl;
	}
}

void Inventory::productDetail(int id) {
	try {
		checkAvailability(id);
		products[id]->displayDetail();
	}
	catch (string e) {
		cout << endl << e;
	}
	
}

void Inventory::allProductDetail() {
	for (int i = 0; i < size; i++) {
		products[i]->displayDetail();
	}
}

void Inventory::updateStock(int id) {
	try {
		checkAvailability(id);
		products[id]->updateDetails();
	}
	catch (string e) {
		cout << endl << e;
	}
	
}

void Inventory::saveToFile(ostream& os) {
	
	for (int i = 0; i < size; i++) {
		try {
			checkFile(os);
			products[i]->saveFile(os);
			
		}
		catch (string e) {
			cout << e << endl;
		}
		
	}
}
void Inventory::loadFromFile(istream& is) {
	for (int i = 0; i < size; i++) {
		products[i]->loadFile(is);
	}
}