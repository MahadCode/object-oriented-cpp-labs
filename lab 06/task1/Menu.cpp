#include "Menu.h"

Menu::Menu() {
	Items = nullptr;
	noItems = 0;
}

void Menu::addItem(item& Adding) {
	if (noItems == 0) {
		noItems++;
		Items = new item *[noItems];
		Items[0] = &Adding;
		return;
	}
	else {
		int prevItems = noItems;

		noItems++;
		item** temp = new item *[noItems];

		for (int i = 0; i < prevItems; i++) {
			temp[i] = Items[i];
		}

		temp[noItems - 1] = &Adding;

		Items = new item * [noItems];
		for  (int i = 0; i < noItems; i++)
		{
			Items[i] = temp[i];
		}

		delete[] temp;
	}
}

void Menu::displayMenu() const {
	cout << endl << "Menu:" << endl;
	for (int i = 0; i < noItems; i++) {
		cout << i + 1 << "   Item" << endl;
		cout << (*Items[i]) << endl;
	}
}
