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
	length = i;
	str = new char[length];
	for (int k = 0; k <= length; k++) {
		str[k] = input[k];
	}
}

MyString::MyString(const char& other) {

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


