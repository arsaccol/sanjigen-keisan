#include <cstdio>
#include "./matrix.h"

int main()
{
    printf("hello there mate\n");

    Matrix<4, 4> mat{
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };

    //mat.print();

    std::cout << mat << std::endl;

    return 0;
}
