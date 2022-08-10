#include <iostream>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    Matrix<double> a("matrix1.txt");
    Matrix<double> I = a.get_inverse();
    a.print();
    I.print();
    Matrix<double> Identity = a * I;
    Identity.print();

    return 0;
}