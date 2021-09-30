#ifndef MATRIX_H
#define MATRIX_H

#include <locale>
#include <initializer_list>
#include <cassert>

class Matrix
{
private:
    double** matrix = nullptr;
    size_t row;
    size_t col;
    double det;

public:
    Matrix(int row, int col);
    Matrix(int row, int coll, double** matrix);
    Matrix(const std::initializer_list<std::initializer_list<double>> listList);

    Matrix(const Matrix &m);
    
    ~Matrix();

    size_t GetRow(){return this->row;}
    size_t GetCol(){return this->col;}

    double *const operator[] (int i);

    Matrix& operator= (const Matrix &m);
    
    Matrix operator+ (const Matrix &m);
    Matrix operator- (const Matrix &m);
    Matrix operator* (const Matrix &m);
    Matrix operator* (const double num);
};

#endif //MATRIX_H