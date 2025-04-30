#include<iostream>
#include"Polynomial.h"
#include"MonicPolynomial.h"
#include"SparsePolynomial.h"
using namespace std;

int main() {
    cout << "First for MoniPolynomial\n";
    int maxPower;
    cout << "Enter the highest power of the Monic Polynomial: ";
    cin >> maxPower;

    double* terms = new double[maxPower];
    cout << "Enter the terms (excluding the term for the highest power, which is 1): " << endl;
    for (int i = 0; i < maxPower; ++i) {
        cout << "Term for x^" << i << ": ";
        cin >> terms[i];
    }

    MonicPolynomial monicPoly(maxPower, terms);
    delete[] terms;

    int choice;
    do {
        cout << "\n1. Evaluate Polynomial" << endl;
        cout << "2. Display Polynomial" << endl;
        cout << "3. Calculate Derivative" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double value;
            cout << "Enter the value for x: ";
            cin >> value;
            cout << "Result: " << monicPoly.evaluate(value) << endl;
            break;
        }
        case 2: {
            cout << "Polynomial: ";
            monicPoly.display();
            break;
        }
        case 3: {
            int order;
            cout << "Enter the derivative order: ";
            cin >> order;
            MonicPolynomial* derived = monicPoly.derivative(order);
            cout << "Derived Polynomial: ";
            derived->display();
            double xValue;
            cout << "Enter a value to evaluate the derived polynomial: ";
            cin >> xValue;
            cout << "Result: " << derived->evaluate(xValue) << endl;
            break;
        }
        case 4:
            cout << "Exiting menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    cout << "Polynomial for SparsePolynomial\n";

    int degree;
    cout << "Enter degree of polynomial: ";
    do {
        cin >> degree;
    } while (degree < 0);

    double* coefficients = new double[degree + 1];
    cout << "Enter coefficients (from 0 to degree): ";
    for (int i = 0; i <= degree; ++i) {
        cin >> coefficients[i];
    }

    SparsePolynomial poly(degree, coefficients);
    delete[] coefficients;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Polynomial\n";
        cout << "2. Evaluate Polynomial\n";
        cout << "3. Compute Derivative\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Polynomial: ";
            poly.display();
            break;
        }
        case 2: {
            double x;
            cout << "Enter value of x: ";
            cin >> x;
            cout << "Value of polynomial at x = " << x << ": " << poly.evaluate(x) << endl;
            break;
        }
        case 3: {
            int order;
            cout << "Enter order of derivative: ";
            cin >> order;
            SparsePolynomial* deriv = poly.derivative(order);
            cout << "Derivative: ";
            deriv->display();
            delete deriv;
            break;
        }
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}