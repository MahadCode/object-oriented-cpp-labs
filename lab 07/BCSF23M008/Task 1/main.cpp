#include<iostream>
#include"MilTime.h"
using namespace std;

int main() {
	int milH;
	cout << "Enter Time in military Format:" << endl;
	cout << "Enter hours (0 to 2359)" << endl;
	do {
		cin >> milH;
	} while (milH < 0 || milH > 2359 || (milH%100) > 59);

	int milS;
	cout << "Enter Seconds (0 to 59) " << endl;
	do {
		cin >> milS;
	} while (milS < 0 || milS > 59);

	MilTime obj1(milH, milS);
	obj1.displayTime();
	cout << "Getting Military Hours:\t" << obj1.getHour();
	cout << "Geting Standard Hourse:\t" << obj1.getStandHr();

	int milh;
	cout << "Setting Time in military Format:" << endl;
	cout << "Enter hours (0 to 2359)" << endl;
	do {
		cin >> milh;
	} while (milh < 0 || milh > 2359 || (milh % 100) > 59);

	int mils;
	cout << "Enter Seconds (0 to 59) " << endl;
	do {
		cin >> mils;
	} while (mils < 0 || mils > 59);
	obj1.setTime(milH, milS);
	obj1.displayTime();
}