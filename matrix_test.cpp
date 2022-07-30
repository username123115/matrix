#include <iostream>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    Matrix a("matrix1.txt");
    Matrix b("matrix2.txt");
    double tolerance = 0.01;
    Matrix X(b.getRows(), 1, 1.0);
    double eigenvalue = 0.0;
    int errorCode;
    std::tie(X, eigenvalue, errorCode) = b.powerIter(b.getRows(), tolerance);
    X.print();
    std::cout << eigenvalue << std::endl;


    return 0;
}