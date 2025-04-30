#pragma once
#include<iostream>
#include<string>
using namespace std;

class Stats
{
private:
	int wins;
	int losses;
	
public:
	int matchPlayed;

	Stats();

	void recordWin();
	void recordLoss();
	void displayStats() const;
};

