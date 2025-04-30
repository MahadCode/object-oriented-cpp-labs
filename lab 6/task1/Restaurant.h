#pragma once
#include<iostream>
#include<string.h>
#include"item.h"
#include"Menu.h"
#include"Table.h"

using namespace std;

class Restaurant
{
	string name;
	Menu menu;
	Table** tables;
	int noTables;
public:
	Restaurant();
	void addTable(Table&);
	void addMenuItems(item&);
	void displayRestaurantInfo() const;
};

