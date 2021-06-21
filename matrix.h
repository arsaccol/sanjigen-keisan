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
};


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
        std::copy(col.begin(), col.end(), data[i]);
        ++i;
    }

    //std::copy(std::begin(values), std::end(values), data);
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
