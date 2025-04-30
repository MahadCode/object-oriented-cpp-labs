#pragma once
#include<iostream>
using namespace std;
class MixedFraction
{
	int integer;
	int numerator;
	int denominator;
public:
	MixedFraction();
	MixedFraction(int a_integer, int a_nmrator, int a_dnmnator);
	MixedFraction(int a_integer);
	MixedFraction(MixedFraction& a_mFrac);
	~MixedFraction();

	//getter
	void setIntegralPart(int a_intgr);
	void setDenominator(int a_dnmnator);
	void setNumerator(int a_nmrator);
	int getIntegralPart();
	int getDenominator();
	int getNumerator();

	int evaluate();
	void display();

	MixedFraction operator+(const MixedFraction&);
	MixedFraction operator-(const MixedFraction&);
	MixedFraction operator*(const MixedFraction&);
	MixedFraction operator/(const MixedFraction&);
	MixedFraction& operator=(const MixedFraction&);
	
};

