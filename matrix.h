#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

using std::vector;
using std::tuple;

template <class T>
class Matrix 
{
public:
    Matrix(unsigned, unsigned, T);
    Matrix(const char *);
    Matrix(const Matrix<T> &);

    //operator overloading
    Matrix<T> operator+(Matrix<T> &); //template support
    Matrix<T> operator-(Matrix<T> &); //template support
    Matrix<T> operator*(Matrix<T> &); //template support
    T& operator()(const unsigned &, const unsigned &); //allows accessing matrix values
    Matrix<T> transpose(); 

    //Scalar Operations
    Matrix<T> operator+(double); 
    Matrix<T> operator-(double);
    Matrix<T> operator*(double);
    Matrix<T> operator/(double);

    void print() const;
    unsigned getRows() const;
    unsigned getCols() const;

    //experimental inverse function
    Matrix<T> get_inverse();
    tuple<Matrix<double>, double, int> powerIter(unsigned, double); //template support
    //Matrix<double> deflation(Matrix<T> &, double&); //template support


private:
    unsigned m_rowSize;
    unsigned m_colSize;
    vector<vector<T> > m_matrix; //template support
};

#endif