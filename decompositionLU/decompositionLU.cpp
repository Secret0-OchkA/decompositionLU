#include <iostream>
#include "Matrix.h"


int main()
{
    //Matrix ma = Matrix(3,2);
    Matrix m1 =
        {
        {1,4,7},
             {2,5,8},
        };
        Matrix m2 =
        {
        {1,4},
             {2,5},
             {3,6}
        };

                
    Matrix m3 = m1 * m2;

        for(int i = 0; i < m2.GetRow(); ++i)
        {
            for(int j = 0; j < m2.GetCol(); ++j)
            {
                std::cout << m2[i][j] << "\t";
            }
            std::cout << std::endl;
        }

    return 0;
}
