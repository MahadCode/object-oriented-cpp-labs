#pragma once
#include<iostream>
using namespace std;

class MyString
{
	char* str;
	int length;
public:
	MyString();
	MyString(char* input);
	MyString(const MyString& other);
	~MyString();

	MyString& operator = (const MyString& other);

	int getLength() const;

	void display() const;

	MyString operator+(const MyString& other) const;
	/*MyString operator=(const MyString& other) const;*/
};








