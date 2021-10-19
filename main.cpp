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

    auto identityMat4 = Matrix<4, 4>::identity();
    std::cout << "Identity Mat<4>: " << std::endl << identityMat4 << std::endl;

    auto mat23 = Matrix<2, 3>{ {1, 2, 3}, {4, 5, 6} };
    auto mat34 = Matrix<3, 4>{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}; 
    auto result = mat23 * mat34;
    std::cout << "Result of multiplication between " << STR(mat23) << " and " << STR(mat34) << std::endl << result << std::endl;

    auto mat4_a = Mat4{
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}, 
    };

    auto mat4_b = Mat4{
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}, 
    };

    auto result_4x4 = mat4_a * mat4_b;
    std::cout << "Result of multiplication between " << STR(mat4_a) << " and " << STR(mat4_b) << std::endl << result_4x4 << std::endl;

    std::cout << "Identity times identity should still be identity, see: " << std::endl << Matrix<3, 3>::identity() * Matrix<3,3>::identity() << std::endl;



    return 0;
}
