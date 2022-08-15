#include <iostream>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    Matrix<double> a = Matrix<double>("matrix1.txt");
    Matrix<double> *m = new Matrix<double>("matrix1.txt");
    std::cout << (*m)(1, 1) << std::endl;
    delete m;
    uint32_t x = 143;
    double y = 0.5;
    std::cout <<(uint32_t) (x * y) << std::endl;

    return 0;
}