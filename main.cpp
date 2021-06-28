#include <cstdio>
#include "./matrix.h"

int main()
{
    printf("hello there mate\n");

    Matrix<4, 4> matA{
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };

    Matrix<4, 4> matB{
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };

    //mat.print();

    std::cout << STR(matA) << std::endl << matA << std::endl;
    std::cout << STR(matB) << std::endl << matB << std::endl;

    Matrix<4, 4> matC{ matA };
    //matC = matA + matB;
    matC = matA + matB;

    std::cout << STR(matC) << std::endl << matC << std::endl;

    return 0;
}
