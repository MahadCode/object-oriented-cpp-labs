#pragma once
#include"item.h"
#include<iostream>
#include<string>

using namespace std;

class Order
{
	item** itemsOrdered;
	int tableNumber;
	int noOrderedItems;
public:
	Order();
	Order& operator += (item&);
	double calculateTotal() const;
	void displayOrder() const;
	void setTableNumber(int);
};

