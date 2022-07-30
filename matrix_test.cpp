#include <iostream>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    Matrix a("matrix1.txt");
    Matrix I = a.get_inverse();
    a.print();
    I.print();
    Matrix Identity = a * I;
    Identity.print();

    return 0;
}