#include "MilTime.h"

MilTime::MilTime(int h, int s) {
	setTime(h, s);
}

void MilTime::setTime(int h, int s) {
	milHours = h;
	milSeconds = s;
	int standardHours = milHours / 100;
	int standardMinutes = milHours % 100;
	setStandardTime(standardHours, standardMinutes, milSeconds);
}

int MilTime::getHour() {
	return milHours;
}

int MilTime::getStandHr(){
	int standardHours = milHours / 100;
	if (standardHours <= 12) {
		return standardHours;
	}
	else {
		return standardHours - 12;
	}
}

void MilTime::displayTime() {
	cout << endl;
	cout << "Military Time:" << endl;
	cout << milHours << " hours" << endl;
	cout << milSeconds << " seconds" << endl;
	cout << endl;
	displayStandardTime();
}