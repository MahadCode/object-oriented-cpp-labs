#include "Time.h"
void Time::setStandardTime(int h, int m, int s) {
	hours = h;
	minutes = m;
	seconds = s;
}

void Time::displayStandardTime() {
	if (hours < 12) {
		cout << "Standard Time:" << endl;
		cout << hours << " : " << minutes << " : " << seconds << " AM" << endl;
	}
	else if (hours == 12) {
		cout << "Standard Time:" << endl;
		cout << hours << " : " << minutes << " : " << seconds << " PM" << endl;
	}
	else {
		int tempH = hours - 12;
		cout << "Standard Time:" << endl;
		cout << tempH << " : " << minutes << " : " << seconds << " PM" << endl;
	}
}