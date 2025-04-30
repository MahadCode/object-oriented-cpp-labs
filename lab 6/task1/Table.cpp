#include "Table.h"

Table::Table() {
	tableNumber = -1;
	order = nullptr;
}

void Table::placeOrder(Order& curr) {
	order = &curr;
}
void Table::displayTableOrder() const {
	cout << "Table  " << tableNumber << ":" << endl;
	order->displayOrder();
}

void Table::setTableNum(int t) {
	tableNumber = t;
}