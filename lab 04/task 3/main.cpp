#include<iostream>
#include"MyString.h"
using namespace std;

int main() {
	char* str = new  char[7];
	cin.getline(str, 7);
	//int k = 7;
	//char arr[7];
	//cin >> arr;
	///*for (int i = 0; i < k; i++) {
	//	cin >> arr[i];
	//}*/

	//arr[k] = '\0';

	MyString x(str);
	x.display();
	MyString y = x;
	y.display();
	cout << x.getLength() << endl;
	MyString y1 = (y + x);
	cout << y1.getLength() << endl;
	y1.display();
	delete[] str;


}