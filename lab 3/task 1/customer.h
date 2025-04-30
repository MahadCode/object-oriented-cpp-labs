#pragma once

#include"account.h"
#include<iostream>
#include<string>
using namespace std;

class customer
{
	string name;
	account Account;
    public:
		customer(string,account);
		void display() const;
};

