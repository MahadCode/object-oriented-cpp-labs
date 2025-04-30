#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial() : degree(0) {
    coefficients = new double[degree + 1];
    coefficients[0] = 0;
}

Polynomial::Polynomial(int degree, const double* coeffs) : degree(degree) {
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        coefficients[i] = coeffs[i];
    }
}

Polynomial::Polynomial(const Polynomial& other) : degree(other.degree) {
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        coefficients[i] = other.coefficients[i];
    }
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this == &other) return *this;

    delete[] coefficients;

    degree = other.degree;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        coefficients[i] = other.coefficients[i];
    }

    return *this;
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

void Polynomial::display() const {
    for (int i = degree; i >= 0; --i) {
        cout << coefficients[i] << "x^" << i;
        if (i > 0) cout << " + ";
    }
    cout << endl;
}

int Polynomial::calculateDerivative(int value) {
    Polynomial* deriv = derivative(1);
    return static_cast<int>(deriv->evaluate(value));
}
