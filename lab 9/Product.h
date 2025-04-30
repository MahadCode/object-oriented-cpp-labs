#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Product
{
	int productID;
	string name;
	int quantity;
	float price;
public:
	Product();
	Product(int, string);
	int getID();
	void updateDetails();
	void addStock(int);
	void removeStock(int);
	void checkAvailability(int);
	void displayDetail();
	void saveFile(ostream&);
	void loadFile(istream&);
};

