#include "item.h"

item::item() {

}

item::item(string n, double p) {
	name = n;
	price = p;
}

ostream& operator << (ostream& out, item& curr) {
	out << "Item's Name:     " << curr.name << endl;
	out << "Item's Price:    " << curr.price << endl;
	out << "Item's Category: " << curr.category << endl;
	out << endl;
	return out;
}

istream& operator >> (istream& in, item& curr) {
	cout << "Enter Item's Name:     " << endl;
	in >> curr.name;
	cout << "Enter Item's Price:    "  << endl;
	in >> curr.price;
	cout << "Enter Item's Category: "  << endl;
	in >> curr.category;
	cout << endl;
	return in;
}

string item::getName() const {
	return name;

}

double item::getPrice() const {
	return price;
}