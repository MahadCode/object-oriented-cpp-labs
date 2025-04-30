#include "MixedFraction.h"

MixedFraction::MixedFraction() {
	integer = 0;
	numerator = 0;
	denominator = 1;
}

MixedFraction::MixedFraction(int a_integer, int a_nmrator, int a_dnmnator) {
	integer = a_integer;
	numerator = a_nmrator;
	denominator = a_dnmnator;
}

MixedFraction::MixedFraction(MixedFraction& a_mFrac) {
	integer = a_mFrac.integer;
	numerator = a_mFrac.numerator;
	denominator = a_mFrac.denominator;
}

MixedFraction::MixedFraction(int a_integer) {
	integer = a_integer;
	numerator = 0;
	denominator = 1;
}

MixedFraction::~MixedFraction() {
	cout << "Object has destroyed" << endl << endl;
}

void MixedFraction::setIntegralPart(int a_intgr) {
	integer = a_intgr;

}
void MixedFraction::setDenominator(int a_dnmnator) {
	denominator = a_dnmnator;
}
void MixedFraction::setNumerator(int a_nmrator) {
	numerator = a_nmrator;
}
int MixedFraction::getIntegralPart() {
	return numerator;
}
int MixedFraction::getDenominator() {
	return denominator;
}
int MixedFraction::getNumerator() {
	return numerator;
}

int MixedFraction::evaluate() {
	return (((denominator * integer) + numerator)/denominator);
}

void MixedFraction::display() {
	cout << "Fraction:" << endl << integer << " " << numerator << "/" << denominator << endl << endl;
}

MixedFraction MixedFraction::operator+(const MixedFraction& s) {
	MixedFraction temp;
	
	int firstNumerator = ((denominator * integer) + numerator);
	int secondNumerator = ((s.denominator * s.integer) + s.numerator);
	
	int temNumerator = ((firstNumerator * s.denominator) + (secondNumerator * denominator));
	temp.denominator = denominator * s.denominator;
	
	temp.numerator = temNumerator % temp.denominator;
	temp.integer = temNumerator / temp.denominator;
	
	return temp;
}

MixedFraction MixedFraction::operator-(const MixedFraction& s) {
	MixedFraction temp;

	int firstNumerator = ((denominator * integer) + numerator);
	int secondNumerator = ((s.denominator * s.integer) + s.numerator);
	
	int temNumerator = ((firstNumerator * s.denominator) - (secondNumerator * denominator));
	temp.denominator = denominator * s.denominator;
	
	temp.numerator = temNumerator % temp.denominator;
	temp.integer = temNumerator / temp.denominator;

	return temp;
}

MixedFraction MixedFraction::operator*(const MixedFraction& s) {
	MixedFraction temp;

	int firstNumerator = ((denominator * integer) + numerator);
	int secondNumerator = ((s.denominator * s.integer) + s.numerator);
	
	int temNumerator = firstNumerator*secondNumerator;
	temp.denominator = denominator * s.denominator;
	
	temp.numerator = temNumerator % temp.denominator;
	temp.integer = temNumerator / temp.denominator;

	return temp;
}

MixedFraction MixedFraction::operator/(const MixedFraction& s) {
	MixedFraction temp;

	int firstNumerator = ((denominator * integer) + numerator);
	int secondNumerator = ((s.denominator * s.integer) + s.numerator);
	
	int temNumerator = firstNumerator * s.denominator;
	temp.denominator = denominator * secondNumerator;
	
	temp.numerator = temNumerator % temp.denominator;
	temp.integer = temNumerator / temp.denominator;

	return temp;
}

MixedFraction& MixedFraction::operator=(const MixedFraction& s) {
	numerator = s.numerator;
	denominator = s.denominator;
		integer = s.integer;
		return (*this);

}