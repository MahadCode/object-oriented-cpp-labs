#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>

class Polynomial {
protected:
    int degree;
    double* coefficients;

public:
    Polynomial();
    Polynomial(int degree, const double* coeffs);
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    virtual ~Polynomial();

    virtual double evaluate(double x) const;
    virtual void display() const;
    virtual Polynomial* derivative(int x) = 0;
    virtual int calculateDerivative(int) = 0;
};

#endif 
