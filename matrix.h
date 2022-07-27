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

class Matrix 
{
public:
    Matrix(unsigned, unsigned, double); //matrix made from specifying row height and data
    Matrix(const char *); //matrix takenffrom data in a file
    Matrix(const Matrix &); //matrix made from matrix
    ~Matrix(); //destructor for matrix class

    //operator overloading
    Matrix operator+(Matrix &);
    Matrix operator-(Matrix &);
    Matrix operator*(Matrix &);
    Matrix transpose();

    //Scalar Operations
    Matrix operator+(double);
    Matrix operator-(double);
    Matrix operator*(double);
    Matrix operator/(double);

    double& operator()(const unsigned &, const unsigned &); //allows accessing matrix values
    void print() const;
    unsigned getRows() const;
    unsigned getCols() const;

    tuple<Matrix, double, int> powerIter(unsigned, double);
    Matrix deflation(Matrix &, double&);

private:
    unsigned m_rowSize;
    unsigned m_colSize;
    vector<vector<double> > m_matrix;
};

#endif