#ifndef PERSON_H
#define PERSON_H
#include<iostream>
using namespace std;
#include<string>

class Person
{
	string name;
	int age;
	string nationalID;
protected:
	string phoneNumber;

public:
	Person();
	string address;
	void setPersonalInfo(string,int,string,string,string);
	void displayPersonalInfo();
};

#endif

