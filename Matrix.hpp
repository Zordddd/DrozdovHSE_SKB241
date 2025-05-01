#pragma once


class Matrix{

    int cols, rows;
    double** numbers;
    static int number_of_matrices;

    bool ZeroCol(int row, int col);
    bool AllZeroCol(int col);
    bool AllZeroRow(int row);
    int MinValueCol(int row, int col);
    void ZerosUnderMain(int row, int col);
    void ZerosUpperMain(int row, int col);
    void printAndCheckAnswer(Matrix& X, Matrix& A, Matrix& B);

public:

    Matrix(int _rows, int _cols);
    Matrix();
    ~Matrix();

    void getMatrix();
    void getMatrix(const char* name_file);

    void printMatrix();
    void printMatrix_in_file(const char* name_file);

    Matrix& operator=(const Matrix& m);
    Matrix operator*(const Matrix& m);
    Matrix operator*(const int number);
    Matrix operator-(const Matrix& m);
    Matrix operator+(const Matrix& m);
    bool operator==(const Matrix& m);
    bool operator==(const int number);
    bool operator!=(const Matrix& m);

    void Swap(int row1, int row2);
    void MultyRow(int row, double multy_value);
    void MultyMergeRows(int row1, int row2, double multy_value);
    void Gauss();

};