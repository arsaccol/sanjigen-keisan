#pragma once

#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <cstdio>
//#include <array>
#include <sstream>
#include <iostream>

#define STR(x) #x


template <int M, int N>
struct Matrix
{
    float data[M][N];
    //std::array<float, M * N> data;


    Matrix(std::initializer_list<std::initializer_list<float>>);
    void print();

    //template <int I, int J>
    //friend std::ostream& operator<<(std::ostream&, const Matrix<I,J>);
};

using Mat4 = Matrix<4,4>;


// ===== nested initializer_list constructor =====
template <int M, int N>
Matrix<M, N>::Matrix(std::initializer_list<std::initializer_list<float>> values)
{
    if(values.size() != M)
        throw std::invalid_argument("Matrix row number is larger than it should");

    //using It = std::initializer_list<float>::iterator;

    size_t i = 0;
    for(auto& col : values)
    {
        if(col.size() != N)
            throw std::invalid_argument("Matrix column number is larger than it should");

        std::copy(col.begin(), col.end(), data[i]);
        ++i;
    }
}
// ===================================================


// ===================== print =======================
template<int M, int N>
void Matrix<M,N>::print()
{
    for(size_t i = 0; i < M; ++i)
    {
        std::stringstream sstr;
        for(size_t j = 0; j < N; ++j)
        {
            sstr << data[i][j] << " ";
        }

        std::cout << sstr.str() << std::endl;
    }
}
// ===================================================


// =============== stream output operator ============
template<int M, int N>
std::ostream& operator<<(std::ostream& out, const Matrix<M,N>& mat)
{
    for(size_t i = 0; i < M; ++i)
    {
        std::stringstream sstr;
        for(size_t j = 0; j < N; ++j)
        {
            sstr << mat.data[i][j] << " ";
        }

        out << sstr.str() << std::endl;
    }

    return out;
}
// ===================================================
