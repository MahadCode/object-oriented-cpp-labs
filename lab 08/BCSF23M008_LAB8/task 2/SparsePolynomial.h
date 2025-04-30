#ifndef SPARSEPOLYNOMIAL_H
#define SPARSEPOLYNOMIAL_H

#include "Polynomial.h"

class SparsePolynomial : public Polynomial {
private:
    int termCount;
    int* powers;
    double* coeffs;

public:
    SparsePolynomial();
    SparsePolynomial(int,const double*);
    SparsePolynomial(const SparsePolynomial& );
    SparsePolynomial& operator=(const SparsePolynomial& );
    ~SparsePolynomial() override;

    double evaluate(double ) const override;
    void display() const override;
    SparsePolynomial* derivative(int ) override;
    int calculateDerivative(int value = 0) override;
};

#endif 
