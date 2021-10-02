#include "Matrix.h"

//Constructors============================================
Matrix::Matrix(){}

Matrix::Matrix(int row, int col) : row(row), col(col)
{
    matrix = new double*[row];
    for (int i = 0; i < row; ++i)
        matrix[i] = new double [col];

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            matrix[i][j] = 0;
}

Matrix::Matrix(int row, int col, double** matrix): row(row),col(col), matrix(matrix){}

Matrix::Matrix(int row, std::vector<double> vector)
{
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<double>> listList)
{
    this->row = listList.size();
    this->col = listList.begin()->size();
    
    matrix = new double* [this->row];
    for (int i = 0; i < this->row; ++i)
        matrix[i] = new double [this->col];
    
    int i = 0;
    for (std::initializer_list<double> list : listList)
    {
        int j = 0;
        for(double num : list)
        {
            this->matrix[i][j] = num;
            ++j;
        }
        ++i;
    }   
    
}

Matrix::Matrix(const Matrix &m): row(m.row),col(m.col)
{    
    matrix = new double* [row];
    for (int i = 0; i < row; ++i)
        matrix[i] = new double [col];
    
    for(int i = 0; i < this->row; ++i)
        for(int j = 0; j < this->col; ++j)
            this->matrix[i][j] = m.matrix[i][j];
}

Matrix::~Matrix()
{
    if(matrix)
    for(int i = 0; i < row; ++i)
        delete[] matrix[i];
    delete[] matrix;
}


//Operations ===========================================
double *const Matrix::operator[](int i)
{
    assert(i >= 0 && i < this->row);
    return matrix[i];
}

Matrix& Matrix::operator=(const Matrix &m)
{
    if(matrix)
    for(int i = 0; i < this->row; ++i)
        delete[] matrix[i];
    delete[] matrix;
    
    this->row = m.row;
    this->col = m.col;
    
    matrix = new double* [row];
    for (int i = 0; i < row; ++i)
        matrix[i] = new double [col];

    for (int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            matrix[i][j] = m.matrix[i][j];
    
    return *this;
}

Matrix Matrix::operator+(const Matrix& m)
{
    if(this->row != m.row || this->col != m.col)
        throw("matrix1.size != matrix2.size");

    Matrix res = Matrix(this->row,this->col);
    for(int i = 0; i < res.row; ++i)
        for(int j = 0; j < res.col; ++j)
            res.matrix[i][j] = m.matrix[i][j] + this->matrix[i][j];
    return res;
}

Matrix Matrix::operator-(const Matrix& m)
{
    if(this->row != m.row || this->col != m.col)
        throw("matrix1.size != matrix2.size");

    Matrix res = Matrix(this->row,this->col);
    for(int i = 0; i < res.row; ++i)
        for(int j = 0; j < res.col; ++j)
            res.matrix[i][j] = m.matrix[i][j] - this->matrix[i][j];
    return res;
}

Matrix Matrix::operator*(const double num)
{
    Matrix res = Matrix(this->row,this->col);
    for(int i = 0; i < res.row; ++i)
        for(int j = 0; j < res.col; ++j)
            res.matrix[i][j] = this->matrix[i][j] * num;
    return res;
}

Matrix Matrix::operator*(const Matrix& m)
{
    if(this->col != m.row )
        throw("matrix1.col != matrix2.row");

    Matrix res = Matrix(this->row,m.col);

    // C(MxN) = A(MxN) * B(NxP)
    //c[i][j] = sum(n=1 -> A.col) { a[i][n] * b[n][j] }
    for(int i = 0; i < res.GetRow(); ++i)
        for(int j = 0; j < res.GetCol(); ++j)
        {
            res.matrix[i][j] = 0;
            for(int n = 0; n < this->GetCol(); ++n)
            {
                res.matrix[i][j] += this->matrix[i][n] * m.matrix[n][j];
            }
        }
    
    return res;
}

void Matrix::get_lu_matrix(Matrix& low, Matrix& up)
{
    //нет более точной проверки потому-что работаем с не выроджеными матрицами
    if(this->col != this->row)
        throw ("col != row");
    
    low = Matrix(this->col,this->col);
    up = Matrix(this->col,this->col);

    for(int i = 0; i < this->col; ++i)
        up.matrix[0][i] = this->matrix[0][i];
    
    for(int i = 0; i < this->col; ++i)
        low.matrix[i][0] = this->matrix[i][0] / this->matrix[0][0];
    

    for(int i = 1; i < this->col; ++i)
        for(int j = i; j < this->col; ++j)
        {
            double sumUp = 0;
            double sumLow = 0;
            for(int k = 0; k < i; ++k)
            {
                sumUp += low.matrix[i][k] * up.matrix[k][j];
                sumLow += low.matrix[j][k] * up.matrix[k][i];
            }
            up.matrix[i][j] = this->matrix[i][j] - sumUp;
            low.matrix[j][i] = (this->matrix[j][i] - sumLow) / up.matrix[i][i];  
        }
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
    for(int i = 0; i < m.row; ++i)
    {
        for(int j = 0; j < m.col; ++j)
        {
            out << m.matrix[i][j] << "\t";
        }
        out  << std::endl;
    }
    out  << std::endl;
    return out;
}







