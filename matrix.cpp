# include "matrix.h"
using namespace std;
template <class T>
Matrix<T>::Matrix(unsigned rowSize, unsigned colSize, T initial)
{
    m_rowSize = rowSize;
    m_colSize = colSize;
    m_matrix.resize(rowSize);
    for (unsigned i = 0; i < m_matrix.size(); i++)
    {
        m_matrix[i].resize(colSize, initial); //fill with initial
    }

}
template <class T>
Matrix<T>::Matrix(const char * filename)
{
ifstream file_A(filename); // input file stream to open the file A.txt

    // Task 1
    // Keeps track of the Column and row sizes
    int colSize = 0;
    int rowSize = 0;
    
    // read it as a vector
    string line_A;
    int idx = 0;
    T element_A;
    T *vector_A = nullptr;
    
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
                T *tempArr = new T[idx + 1];
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
template <class T>
Matrix<T>::Matrix(const Matrix<T>&B)
{
    m_rowSize = B.getRows();
    m_colSize = B.getCols();
    m_matrix = B.m_matrix;

}

//arithmetic
template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &B)
{
    Matrix<T> sum(m_colSize, m_rowSize, (T) 0);
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            sum(i, j) = this->m_matrix[i][j] + B(i, j);
        }
    }
    return sum;
}
template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &B)
{
    Matrix<T> diff(m_colSize, m_rowSize, (T) 0);
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            diff(i, j) = this->m_matrix[i][j] - B(i, j);
        }
    }
    return diff;
}
template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &B)
{
    Matrix<T> product(m_rowSize, B.getCols(), (T) 0);
    if(m_colSize == B.getRows()) 
    {
        unsigned i, j, k;
        T temp = 0;
        for (i = 0; i < m_rowSize; i++)
        {
            for (j = 0; j < B.getCols(); j++)
            {
                temp = (T) 0;
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
 template <class T>
 Matrix<T> Matrix<T>::operator+(double scalar)
 {
    Matrix sum(m_rowSize, m_colSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            sum(i, j) = (T) (m_matrix[i][j] + scalar);
        }
    }
    return sum;
 }
template <class T>
 Matrix<T> Matrix<T>::operator-(double scalar)
 {
    Matrix diff(m_rowSize, m_colSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            diff(i, j) = (T) (m_matrix[i][j] - scalar);
        }
    }
    return diff;
 }
template <class T>
 Matrix<T> Matrix<T>::operator*(double scalar)
 {
    Matrix product(m_rowSize, m_colSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            product(i, j) = (T) (m_matrix[i][j] * scalar);
        }
    }
    return product;
 }
 template <class T>
  Matrix<T> Matrix<T>::operator/(double scalar)
 {
    Matrix product(m_rowSize, m_colSize, 0.0);
    unsigned i, j;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < m_colSize; j++)
        {
            product(i, j) = (T) (m_matrix[i][j] / scalar);
        }
    }
    return product;
 }
 template <class T>
T& Matrix<T>::operator()(const unsigned &rowNo, const unsigned & colNo)
{
    return this->m_matrix[rowNo][colNo];
}
template <class T>
unsigned Matrix<T>::getRows() const
{
    return this->m_rowSize;
}
template <class T>
unsigned Matrix<T>::getCols() const
{
    return this->m_colSize;
}
template <class T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> Transposed(m_colSize, m_rowSize, (T) 0);
    unsigned i, j;
    for (i = 0; i < m_colSize; i++)
    {
        for (unsigned j = 0; j < m_rowSize; j++)
        {
            Transposed(i, j) = this->m_matrix[j][i];
        }
    }
    return Transposed;
}
template <class T>
void Matrix<T>::print() const
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
template <class T> //only works on square matrices
tuple<Matrix<double>, double, int> Matrix<T>::powerIter(unsigned rowNum, double tolerance)
{
    //initiate guess
    Matrix<double> X(rowNum, 1, 1.0);
    for (unsigned i = 1; i <= rowNum; i++)
    {
        X(i-1, 0) = i;
    }
    int errorCode = 0;
    double difference = 1.0; //used for finding when to stop after changes are small enough
    unsigned iterations = 0;
    unsigned location; //where largest located
    vector<double> eigen;
    double eigenvalue = 0.0;
    eigen.push_back(0.0);

    while (abs(difference) > tolerance) //if change between last two guesses too large keep going else return
    {
        iterations++;
        for (int i = 0; i < rowNum; ++i) //get infinite norm aka greatest value in vector
        {
            eigenvalue = X(0, 0);
            if (abs(X(i, 0)) >= abs(eigenvalue))
            {
                eigenvalue = X(i, 0);
                location = i;
            }
        }
        if (iterations >= 5e5)
        {
            cout <<"Iterations exceeded maximum amount" << endl;
            errorCode = -1;
            return make_tuple(X, 0.0, errorCode);
        }
        eigen.push_back(eigenvalue);
        difference = eigen[iterations] - eigen[iterations - 1];
        X = X / eigenvalue;
        X = (*this) * X; //multiply guess by matrix
    }
    X = X / eigenvalue;
    return make_tuple(X, eigenvalue, errorCode);
}

//ignoring this function for now
/*
template <class T>
Matrix<double> Matrix<T>::deflation(Matrix<T> &X, double &eigenvalue)
{
    // Deflation formula exactly applied
    double denominator = eigenvalue / (X.transpose() * X)(0,0);
    Matrix Xtrans = X.transpose();
    Matrix RHS = (X * Xtrans);
    Matrix RHS2 = RHS * denominator;
    Matrix A2 = *this - RHS2;
    return A2;
} 
*/
template <class T>
Matrix<T> Matrix<T>::get_inverse()
{
    //Initialize Identity Matrix
    //Perform elementary operations to reduce matrix to row echelon form
    if (m_rowSize != m_colSize)
    {
        exit(1);
    }
    else
    {
        //Initializing Identity and copy to operate on
        Matrix Identity(m_rowSize, m_colSize, 0.0);
        for (int i = 0; i < m_rowSize; i++)
        {
            Identity(i, i) = 1.0;
        }
        Matrix elementary(Identity);
        Matrix copy(*this);
        //row echelon form
        for (int i = 0; i < m_rowSize; i++)
        {
            if (copy(i, i) != 1.0)
            {
                elementary(i, i) = (1.0 / copy(i, i));
                copy = elementary * copy;
                Identity = elementary * Identity;
                //set back to identity matrix
                elementary(i, i) = 1.0;
            }
            if (i != m_rowSize - 1)
            {
                for (int j = i + 1; j < m_rowSize; j++)
                {
                    double temp = copy(j, i);
                    elementary(j, i) = (-1.0 * temp);
                    copy = elementary * copy;
                    Identity = elementary * Identity;
                    //copy.print();
                    //std::cout << "Operation performed: " << std::endl;
                    //elementary.print();
                    elementary(j, i) = 0.0;
                }
            }
        }
        //iterate through indices 1-end
        //iterate through j, j < i
        for (int i = 1; i < m_rowSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                double temp = copy(j, i);
                elementary(j, i) = (-1.0 * temp);
                copy = elementary * copy;
                Identity = elementary * Identity;
                elementary(j, i) = 0.0;
            }
        }

        return Identity;
    }
}