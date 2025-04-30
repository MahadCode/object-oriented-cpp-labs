#include<iostream>
#include"MyString.h"
using namespace std;

int main() {
	int k = 7;
	char arr[7];
	for (int i = 0; i < k; k++) {
		cin >> arr[i];
	}
	arr[k] = '\0';

	MyString x(arr);

}