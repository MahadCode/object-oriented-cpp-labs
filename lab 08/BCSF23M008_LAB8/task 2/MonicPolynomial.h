#ifndef MONICPOLYNOMIAL_H
#define MONICPOLYNOMIAL_H

#include "Polynomial.h"

class MonicPolynomial : public Polynomial {
public:
    MonicPolynomial();
    MonicPolynomial(int degree, const double* coeffs);
    MonicPolynomial(const MonicPolynomial& other);
    MonicPolynomial& operator=(const MonicPolynomial& other);

    double evaluate(double x) const override;
    void display() const override;
    MonicPolynomial* derivative(int x) override;
    int calculateDerivative(int) override;
};

#endif 


