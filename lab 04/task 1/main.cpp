#include<iostream>
#include"MixedFraction.h"
using namespace std;

bool check(int x) {
	if (x > 0) {
		return true;
	}
	else
	{
		return false;
	}
}
bool check1(int x) {
	if (x <= 0) {
		return false;
	}
	else
	{
		return true;
	}
}

int main() {

	cout << "First Mixed Fraction:" << endl;
	int intg;

	cout << "Enter Integral Part:" << endl;
		cin >> intg;

		int n;
	cout << "Enter Numerator: " << endl;
    while(true){
		cin >> n;
		if (check(n)) {
			break;
		}
	} 

	int d;
	cout << "Enter Denomerator: " << endl;
	while (true) {
		cin >> d;
		if (check(d)) {
			break;
		}
	}

	MixedFraction x1(intg, n, d);

	cout << "First Mixed Fraction:" << endl;
	int intg1;

	cout << "Enter Integral Part:" << endl;
		cin >> intg1;

		int n1;
	cout << "Enter Numerator: " << endl;
	while (true) {
		cin >> n1;
		if (check(n1)) {
			break;
		}
	}

	int d1;
	cout << "Enter Denomerator: " << endl;
	while (true) {
		cin >> d1;
		if (check(d1)) {
			break;
		}
	}

	MixedFraction x2(intg, n1, d1);
	MixedFraction ans;
	x1.display();
	x2.display();
	ans = x1 + x2;
	ans.display();
	ans = x1 - x2;
	ans.display();
	ans = x1 * x2;
	ans.display();
	ans = x1 / x2;
	ans.display();
}