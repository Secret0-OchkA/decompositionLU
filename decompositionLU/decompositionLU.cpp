#include <iostream>
#include <vector>

#include "Matrix.h"

Matrix calculateSLAY_L(Matrix low,Matrix b);
Matrix calculateSLAY_U(Matrix up, Matrix y);


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

    Matrix low,up;
    a.get_lu_matrix(low,up);
    std::cout << "low:\n" << low << std::endl;
    std::cout << "up:\n"  << up  << std::endl;

    Matrix y = calculateSLAY_L(low,b);
    std::cout << "y:\n" << y << std::endl;

    Matrix x = calculateSLAY_U(up,y);
    std::cout << "x:\n" << x << std::endl;

    
    return 0;
}

//function for tasks
Matrix calculateSLAY_L(Matrix low, Matrix b)
{
    std::vector<double> row;

    for(int i = 0; i < low.GetCol(); ++i)
    {
        double sum = 0;
        for(int j = 0; j < i; ++j)
        {
            double l = low[i][j];
            double bi = row[j];
            sum += l * bi;
        }
        sum = b[i][0] - sum;
        row.push_back(sum);
    }
    return Matrix(false,row);
}

Matrix calculateSLAY_U(Matrix up, Matrix y)
{
    std::vector<double> row;
    for(int i = 0; i < y.GetRow(); ++i)
        row.push_back(y[i][0]);
    
    for(int i = up.GetCol() - 1; i >= 0; --i)
    {
        double sum = 0;
        for(int j = up.GetCol() - 1; j > i; --j)
        {
            double u = up[i][j];
            double yi = row[j];
            sum += u * yi;
        }
        sum = (y[i][0] - sum) / up[i][i];
        row[i] = sum;
    }
    return Matrix(false,row);
}
