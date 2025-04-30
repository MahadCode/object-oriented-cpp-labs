#include "SparsePolynomial.h"
using namespace std;

SparsePolynomial::SparsePolynomial() : Polynomial(), termCount(0), powers(nullptr), coeffs(nullptr) {}

SparsePolynomial::SparsePolynomial(int degree, const double* coefficients)
    : Polynomial(degree, coefficients), termCount(0), powers(nullptr), coeffs(nullptr) {
    for (int i = 0; i <= degree; ++i) {
        if (coefficients[i] != 0) {
            ++termCount;
        }
    }
    powers = new int[termCount];
    coeffs = new double[termCount];
    int index = 0;
    for (int i = 0; i <= degree; ++i) {
        if (coefficients[i] != 0) {
            powers[index] = i;
            coeffs[index] = coefficients[i];
            ++index;
        }
    }
}

SparsePolynomial::SparsePolynomial(const SparsePolynomial& other) : Polynomial(other),termCount(other.termCount) {
    powers = new int[termCount];
    coeffs = new double[termCount];
    for (int i = 0; i < termCount; ++i) {
        powers[i] = other.powers[i];
        coeffs[i] = other.coeffs[i];
    }
}

SparsePolynomial& SparsePolynomial::operator=(const SparsePolynomial& other) {
    if (this == &other) return *this;

    delete[] coefficients;
    delete[] powers;
    delete[] coeffs;

    degree = other.degree;
    termCount = other.termCount;
    coefficients = new double[degree];
    for (int i = 0; i < degree; i++) {
        coefficients[i] = other.coefficients[i];
    }
    powers = new int[termCount];
    coeffs = new double[termCount];
    for (int i = 0; i < termCount; ++i) {
        powers[i] = other.powers[i];
        coeffs[i] = other.coeffs[i];
    }

    return *this;
}

SparsePolynomial::~SparsePolynomial() {
    delete[] powers;
    delete[] coeffs;
}

double SparsePolynomial::evaluate(double x) const {
    double result = 0;
    for (int i = 0; i < termCount; ++i) {
        result += coeffs[i] * pow(x, powers[i]);
    }
    return result;
}

void SparsePolynomial::display() const {
    for (int i = 0; i < termCount; ++i) {
        cout << coeffs[i] << "x^" << powers[i];
        if (i < termCount - 1) cout << " + ";
    }
    cout << endl;
}

SparsePolynomial* SparsePolynomial::derivative(int order) {
    if (order > termCount) {
        double zeroCoeff = 0;
        return new SparsePolynomial(0, &zeroCoeff);
    }

    int maxPower = powers[0];  // Highest power in sparse terms
    double* newCoefficients = new double[maxPower + 1]();
    for (int i = 0; i < termCount; ++i) {
        double coeff = coeffs[i];
        int power = powers[i];

        for (int j = 0; j < order; ++j) {
            if (power == 0) {
                coeff = 0;
                break;
            }
            coeff *= power;
            --power;
        }

        if (coeff != 0 && power >= 0) {
            newCoefficients[power] = coeff;
        }
    }

    SparsePolynomial* deriv = new SparsePolynomial(maxPower, newCoefficients);
    delete[] newCoefficients;

    return deriv;
}




int SparsePolynomial::calculateDerivative(int value) {
    return Polynomial::calculateDerivative(value);
}
