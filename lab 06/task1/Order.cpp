#include "Order.h"

Order::Order() {
	itemsOrdered = nullptr;
	noOrderedItems = 0;
	tableNumber = -1;
}

Order& Order::operator += (item& curr) {
	if (noOrderedItems == 0) {
		noOrderedItems++;
	    itemsOrdered = new item * [noOrderedItems];
		itemsOrdered[0] = &curr;
		return *this;
	}
	int prev = noOrderedItems;
	noOrderedItems++;
	item** temp = new item*[noOrderedItems];
	for (int i = 0; i < prev; i++) {
			temp[i] = itemsOrdered[i];
	 }
	temp[noOrderedItems - 1] = &curr;
	itemsOrdered = new item*[noOrderedItems];
	for (int i = 0; i < noOrderedItems; i++) {
		itemsOrdered[i] = temp[i];
	}
	delete[] temp;
	return *this;
     
}

double Order::calculateTotal() const {
	double sum = 0;
	for (int i = 0; i < noOrderedItems; i++) {
		sum += itemsOrdered[i]->getPrice();
	}
	return sum;
}
void Order::displayOrder() const {
	cout << "Here's Your Order" << endl;
	for (int i = 0; i < noOrderedItems; i++) {
		cout << (*itemsOrdered[i]);
	}
}

void Order::setTableNumber(int t) {
	tableNumber = t;
}