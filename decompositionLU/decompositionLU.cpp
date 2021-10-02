#include <iostream>
#include <vector>

#include "Matrix.h"

void foo(Matrix A, Matrix b);

int main()
{
    //Matrix ma = Matrix(3,2);
    Matrix a =
        {
        {2,4,3},
             {3,1,-2},
             {4,11,7}
        };

    Matrix b =
        {
        {10},
        {2},
        {3},
        };

    foo(a,b);
    

    return 0;
}

void foo(Matrix a, Matrix b)
{
    Matrix low;
    Matrix up;
    a.get_lu_matrix(low,up);

    std::vector<double> row;
    //row.push_back(b[0][0]);
    
    for(int i = 0; i < a.GetCol(); ++i)
    {
        double sum = 0;
        for(int j = 0; j < i; ++j)
        {
            double l = low[i][j];
            double bi = row[i - 1];
            sum += l * bi;
        }
        sum = b[i][0] - sum;
        row.push_back(sum);
    }
}

