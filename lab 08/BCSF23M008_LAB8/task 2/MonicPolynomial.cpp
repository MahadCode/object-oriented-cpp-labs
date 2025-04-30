#include "MonicPolynomial.h"

MonicPolynomial::MonicPolynomial() : Polynomial() {}

MonicPolynomial::MonicPolynomial(int degree, const double* coefficients) : Polynomial(degree, coefficients) {
    this->coefficients[degree] = 1;
}

double MonicPolynomial::evaluate(double x) const {
    return Polynomial::evaluate(x);
}

void MonicPolynomial::display() const {
    Polynomial::display();
}

MonicPolynomial* MonicPolynomial::derivative(int order) {
    if (order > degree) {
        MonicPolynomial* deriv = new MonicPolynomial;
        return deriv;
    };
    MonicPolynomial* deriv = new MonicPolynomial(degree - order, nullptr);
    deriv->coefficients = new double[deriv->degree + 1];

    // Compute the derivative logic
    for (int i = 0; i <= deriv->degree; i++) {
        deriv->coefficients[i] = coefficients[i + order];
        for (int j = 1; j <= order; j++) {
            deriv->coefficients[i] *= (i + j);
        }
    }
    return deriv;
}

int MonicPolynomial::calculateDerivative(int value) {
    return Polynomial::calculateDerivative(value);
}

MonicPolynomial::MonicPolynomial(const MonicPolynomial& other) : Polynomial(other) {

}

MonicPolynomial& MonicPolynomial::operator=(const MonicPolynomial& other) {
    if (this == &other) return *this;
    delete[] coefficients;
    degree = other.degree;
    coefficients = new double[degree];
    for (int i = 0; i < degree; i++) {
        coefficients[i] = other.coefficients[i];
    }
    return *this;
}
