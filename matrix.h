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
    float data[M][N]{};
    //std::array<float, M * N> data;


    Matrix() = default;
    Matrix(std::initializer_list<std::initializer_list<float>>);
    Matrix(const Matrix& other);
    Matrix<M, N>& operator=(const Matrix<M,N>& other);

    static Matrix<M, N> identity();
    void print();

    //template <int I, int J>
    //friend std::ostream& operator<<(std::ostream&, const Matrix<I,J>);
};

using Mat4 = Matrix<4,4>;


template <int N>
struct Mat : public Matrix<N,N>
{
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
        if(col.size() != N)
            throw std::invalid_argument("Matrix column number is larger than it should");

        std::copy(col.begin(), col.end(), data[i]);
        ++i;
    }
}
// ===================================================


// ================ copy constructor ==================
template <int M, int N>
Matrix<M,N>::Matrix(const Matrix<M,N>& other)
{
    for(size_t i = 0; i < M; ++i)
    {
        std::copy_n(other.data[i], N, data[i]);
    }
}
// ===================================================
    

// ================ copy assignment operator ==================
template <int M, int N>
Matrix<M,N>& Matrix<M,N>::operator=(const Matrix<M,N>& other)
{
    for(size_t i = 0; i < M; ++i)
    {
        std::copy_n(other.data[i], N, data[i]);
    }

    return *this;
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


// =================== matrix addition ===============
template<int M, int N>
Matrix<M,N> operator+(const Matrix<M,N>& lhs, const Matrix<M,N>& rhs)
{
    Matrix<M, N> mat;
    std::cout << "It's matrix addition time!" << std::endl;

    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            mat.data[i][j] = lhs.data[i][j] + rhs.data[i][j];
        }
    }

    // wasteful copies? optimize later with move semantics I suppose?
    return mat;
}
// ===================================================


// ================ get identity matrix ==============
template<int M, int N>
Matrix<M, N> Matrix<M,N>::identity()
{
    if(M != N)
        throw std::invalid_argument{"Wrong matrix dimensions: identity matrix must be square"};

    Matrix<M, N> idMat;
    for(size_t i = 0; i < M; ++i)
        idMat.data[i][i] = 1;

    return idMat;
}
// ===================================================



