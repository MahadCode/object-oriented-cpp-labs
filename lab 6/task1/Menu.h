#pragma once
#include"item.h"
#include<iostream>
#include<string>

using namespace std;
class Menu
{
	item** Items;
	int noItems;
public:
	Menu();
	void addItem(item&);
	void displayMenu() const;
};

