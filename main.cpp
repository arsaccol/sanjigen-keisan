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

    std::cout << "Identity matrix: " << std::endl << Matrix<4,4>::identity() << std::endl;
    try {
        std::cout << "Trying to get id matrix with wrong size..." << std::endl;
        std::cout << Matrix<4,3>::identity() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << "Something wrong happened (as expected), let's see what it is: " << std::endl << e.what() << std::endl;
    }


    return 0;
}
