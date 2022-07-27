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
        for (j = 0; j < m_col_size; j++)
        {
            sum(i, j) = this->m_matrix[i][j] + B(i, j);
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