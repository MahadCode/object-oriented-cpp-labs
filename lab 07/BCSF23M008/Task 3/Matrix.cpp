#include "Matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
}

void Matrix::input() {
    cout << "Enter the matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> data[i][j];
        }
    }
}

void Matrix::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        cout << "Matrix multiplication not possible. The number of columns of the first matrix must equal the number of rows of the second matrix." << endl;
        return Matrix(0, 0);
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

void Matrix::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    outFile << rows << " " << cols << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outFile << data[i][j] << " ";
        }
        outFile << endl;
    }
}

void Matrix::readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    inFile >> rows >> cols;

    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;

    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inFile >> data[i][j];
        }
    }

    inFile.close();
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}
