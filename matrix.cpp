# include "matrix.h"
using namespace std;

Matrix::Matrix(unsigned rowSize, unsigned colSize, double initial)
{
    m_rowSize = rowsize;
    m_colSize = colSize;
    m_matrix.resize(rowSize);
    for (unsigned i = 0; i < m_matrix.size(); i++)
    {
        m_matrix[i].resize(colSize, initial);
    }

}
Matrix::Matrix(const char * filename)
{
ifstream file_A(fileName); // input file stream to open the file A.txt

    // Task 1
    // Keeps track of the Column and row sizes
    int colSize = 0;
    int rowSize = 0;
    
    // read it as a vector
    string line_A;
    int idx = 0;
    double element_A;
    double *vector_A = nullptr;
    
    if (file_A.is_open() && file_A.good())
    {
        // cout << "File A.txt is open. \n";
        while (getline(file_A, line_A))
        {
            rowSize += 1;
            stringstream stream_A(line_A);
            colSize = 0;
            while (1)
            {
                stream_A >> element_A;
                if (!stream_A)
                    break;
                colSize += 1;
                double *tempArr = new double[idx + 1];
                copy(vector_A, vector_A + idx, tempArr);
                tempArr[idx] = element_A;
                vector_A = tempArr;
                idx += 1;
            }
        }
    }
    else
    {
        cout << " File failed to open. \n";
    }
    
    int j;
    idx = 0;
    m_matrix.resize(rowSize);
    for (unsigned i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(colSize);
    }
    for (int i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            this->m_matrix[i][j] = vector_A[idx];
            idx++;
        }
    }
    m_colSize = colSize;
    m_rowSize = rowSize;
    delete [] vector_A; // Tying up loose ends

}

//arithmetic
Matrix Matrix::operator+(Matrix &B)
{
    Matrix sum(m_colSize, m_rowSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            sum(i, j) = m_matrix[i][j] + B(i, j);
        }
    }
    return sum;
}
Matrix Matrix::operator-(Matrix &B)
{
    Matrix diff(m_colSize, m_rowSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            diff(i, j) = this->m_matrix[i][j] + B(i, j);
        }
    }
    return diff;
}
Matrix Matrix::operator*(Matrix &B)
{
    Matrix product(m_rowSize, B.getCols(), 0.0);
    if(m_colSize == B.getRows()) 
    {
        unsigned i, j, k;
        double temp = 0.0;
        for (i = 0; i < m_rowSize; i++)
        {
            for (j = 0; j < B.getCols(); j++)
            {
                temp = 0.0;
                for (k = 0; k < m_colSize; k++)
                {
                    temp += m_matrix[i][k] * B(k, j); //calculating dot product
                }
                product(i, j) = temp;
            }
        }
        return product;
    }
    else
    {
        exit(1);
    }
}
 //scaler operations
 Matrix Matrix::operator+(double scalar)
 {
    Matrix sum(m_rowSize, m_colSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize, i++)
    {
        for (j = 0; j < m_colSize, j++)
        {
            sum(i, j) = m_matrix[i][j] + scalar;
        }
    }
    return product;
 }

 Matrix Matrix::operator-(double scalar)
 {
    Matrix diff(m_rowSize, m_colSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize, i++)
    {
        for (j = 0; j < m_colSize, j++)
        {
            diff(i, j) = m_matrix[i][j] - scalar;
        }
    }
    return diff;
 }

 Matrix Matrix::operator*(double scalar)
 {
    Matrix product(m_rowSize, m_colSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize, i++)
    {
        for (j = 0; j < m_colSize, j++)
        {
            product(i, j) = m_matrix[i][j] * scalar;
        }
    }
    return product;
 }
  Matrix Matrix::operator/(double scalar)
 {
    Matrix product(m_rowSize, m_colSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize, i++)
    {
        for (j = 0; j < m_colSize, j++)
        {
            product(i, j) = m_matrix[i][j] / scalar;
        }
    }
    return product;
 }
double& Matrix::operator()(const unsigned &rowNo, cont unsigned & colNo)
{
    return this->m_matrix[rowNo][colNo];
}
unsigned Matrix::getRows() const
{
    return this->m_rowSize;
}
unsigned Matrix::getCols() const
{
    return this->m_colSize;
}

Matrix Matris::transpose()
{
    Matrix Transposed(m_colSize, m_rowSize, 0.0);
    unsigned i, j;
    for (i = 0 < i < m_colSize, i++)
    {
        for (unsigned j = 0; j < m_rowSize, j++)
        {
            Transposed(i, j) = this->m_matrix[j][i];
        }
    }
    return Transposed;
}

void Matrix::print() const
{
    cout << "Matrix: " << endl;
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            cout << "[" << m_matrix[i][j] << "] ";
        }
        cout << endl;
    }
}