#pragma once
#include<iostream>
using namespace std;

class Time
{
private:
	  int hours;
	  int minutes;
	  int seconds;
public:
	void setStandardTime(int, int, int);
	void displayStandardTime();
};

