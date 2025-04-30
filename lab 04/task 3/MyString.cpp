#include "MyString.h"

MyString::MyString() {
	str = nullptr;
	length = 0;
}
MyString::MyString(char* input) {
	int i = 0;
	while (input[i] != '\0') {
		i++;
	}
	i++;
	length = i;
	str = new char[length];
	for (int k = 0; k <= length; k++) {
		str[k] = input[k];
	}
}

MyString::MyString(const MyString& other) {
	length = other.length;
	str = new char(length);
	for (int i = 0; i < length; i++) {
		str[i] = other.str[i];
	}
}
MyString::~MyString() {
	delete[] str;

}

int MyString::getLength() const {
	return length;
}

void MyString::display() const {
	for (int i = 0; i < length; i++) {
		cout << str[i];
	}
	cout << endl;
}

MyString MyString::operator+(const MyString& other) const {
	MyString temp;
	temp.length = length + other.length - 1;
	temp.str = new char[100000];
	int i = 0;
	for (i = 0; i < (length-1) ; i++) {
		temp.str[i] = str[i];
		cout << temp.str[i];
	}
	i--;
	int k = 0;
	while (i < other.length) {
		temp.str[i] = other.str[k];
		cout << temp.str[i];
		i++;
		k++;
	}
	return temp;
}