#ifndef MATRIX_H
#define MATRIX_H

#include <locale>
#include <initializer_list>
#include <iostream>
#include <cassert>
#include <vector>

class Matrix
{
private:
    double** matrix = nullptr;
    size_t row = 0;
    size_t col = 0;
    //double det;

public:
    //Constructors============================================
    Matrix();
    Matrix(int row, int col);
    Matrix(int row, int coll, double** matrix);
    Matrix(int row, std::vector<double> vector);
    Matrix(const std::initializer_list<std::initializer_list<double>> listList);
    Matrix(const Matrix &m);
    
    ~Matrix();

    
    size_t GetRow(){return this->row;}
    size_t GetCol(){return this->col;}

    //Operations ===========================================
    double *const operator[] (int i);

    Matrix& operator= (const Matrix &m);
    
    Matrix operator+ (const Matrix &m);
    Matrix operator- (const Matrix &m);
    Matrix operator* (const Matrix &m);
    Matrix operator* (const double num);

    void get_lu_matrix(Matrix &low, Matrix &up);

    //output ==============================================
    friend std::ostream& operator<<(std::ostream& out, const Matrix &m);
  
};

#endif //MATRIX_H