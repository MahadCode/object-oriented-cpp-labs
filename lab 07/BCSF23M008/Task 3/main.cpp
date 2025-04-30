#include "Matrix.h"
#include<iostream>
#include <fstream>
using namespace std;

int main() {
    int rows1, cols1;

    do {
        cout << "Enter rows and columns for the first matrix (positive integers only): ";
        cin >> rows1;
        cin >> cols1;
    } while (rows1 <= 0 || cols1 <= 0);

    Matrix m1(rows1, cols1);
    cout << "Enter the elements for the first matrix:\n";
    m1.input();
    m1.saveToFile("mat1.txt");

    int rows2, cols2;
    do {
        cout << "Enter rows and columns for the second matrix (positive integers only): ";
        cin >> rows2;
        cin >> cols2;
    } while (rows2 <= 0 || cols2 <= 0);

    Matrix m2(rows2, cols2);
    cout << "Enter the elements for the second matrix:\n";
    m2.input();
    m2.saveToFile("mat2.txt");

    Matrix mat1FromFile(0, 0);
    Matrix  mat2FromFile(0, 0);
    mat1FromFile.readFromFile("mat1.txt");
    mat2FromFile.readFromFile("mat2.txt");
    
    Matrix result = mat1FromFile * mat2FromFile;

    if (result.getRows() > 0 && result.getCols() > 0) {
        result.saveToFile("mat1mat2.txt");
        cout << "Resultant matrix saved to mat1mat2.txt\n";
        cout << "Resultant Matrix:\n";
        result.display();
    }
    else {
        cout << "Matrix multiplication not possible with the given dimensions.\n";
    }

    return 0;
}
