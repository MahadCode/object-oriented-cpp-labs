#pragma once
#include"Product.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Inventory
{
	Product** products;
	int size;
	int capacity;

public:
	void addProduct(Product&);
	void removeProduct(Product&);
	void updateStock(int);
	void addStock(Product&, int);
	void removeStock(Product&, int);
	void checkAvailability(int);
	void productDetail(int);
	void allProductDetail();
	void saveToFile(ostream&);
	void loadFromFile(istream&);
};

