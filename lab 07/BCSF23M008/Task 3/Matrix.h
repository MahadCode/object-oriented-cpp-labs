#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    Matrix(int r, int c);
    ~Matrix();
    void input();
    void display() const;
    Matrix operator*(const Matrix& other) const;
    void saveToFile(const string& filename) const;
    void readFromFile(const string& filename);

    int getRows() const;


    int getCols() const;
};

#endif
