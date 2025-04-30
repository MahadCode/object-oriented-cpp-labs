#pragma once
#include<iostream>
#include<string>

using namespace std;

class item
{
	string name;
	double price;
	string category;
public:
	item();
	item(string, double);
	friend ostream& operator << (ostream&, item&);
	friend istream& operator >> (istream&, item&);
	string getName() const;
	double getPrice() const;
};

