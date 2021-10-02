#include <iostream>
#include <vector>

#include "Matrix.h"

void foo(Matrix A, Matrix b);

int main()
{
    //Matrix ma = Matrix(3,2);
    Matrix m1 =
        {
        {2,4,3},
             {3,1,-2},
             {4,11,7}
        };

    Matrix low;
    Matrix up;

    m1.get_lu_matrix(low,up);
    std::cout << "matrix:\n" << m1 << std::endl;
    std::cout << "low:\n" << low << std::endl;
    std::cout << "up:\n" << up << std::endl;

    return 0;
}

void foo(Matrix a, Matrix b)
{
    Matrix low;
    Matrix up;
    a.get_lu_matrix(low,up);

    for(int i = 0; i < a.GetCol(); ++i)
        for(int j = 0; j < a.GetCol(); ++j)
        {
            std::vector<double> row;
            row.push_back(low[i][j]);//
        }
}

