#pragma once
#include<iostream>
#include<string>
#include"Order.h"

using namespace std;
class Table
{
	int tableNumber;
	Order* order;
public:
	Table();
	void setTableNum(int);
	void placeOrder(Order&);
	void displayTableOrder() const;

};

