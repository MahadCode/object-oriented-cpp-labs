#include "Restaurant.h"

Restaurant::Restaurant() {
	name = "null";
	tables = nullptr;
	noTables = 0;
}



void Restaurant::addTable(Table& curr) {
	if (noTables == 0) {
		noTables++;
		tables = new Table * [noTables];
		tables[0] = &curr;
		return;
	}
	int prev = noTables;
	noTables++;
	Table** temp = new Table * [noTables];
	for (int i = 0; i < prev; i++) {
		temp[i] = tables[i];
	}
	temp[noTables - 1] = &curr;
	tables = new Table * [noTables];
	for (int i = 0; i < noTables; i++) {
		tables[i] = temp[i];
	}
	delete[] temp;
}

void Restaurant::addMenuItems(item& curr) {
	menu.addItem(curr);
}

void Restaurant::displayRestaurantInfo() const {
	menu.displayMenu();
	for (int i = 0; i < noTables; i++) {
		tables[i]->displayTableOrder();
	}
}