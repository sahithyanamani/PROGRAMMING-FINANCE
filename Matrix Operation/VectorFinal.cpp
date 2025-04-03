#include <iostream>
#include <vector>

using namespace std;

// Define matrix as a vector of vectors of doubles
typedef vector<vector<double> > Matrix;

void Addition(const Matrix& matA, const Matrix& matB, Matrix& result);
void Subtraction(const Matrix& matA, const Matrix& matB, Matrix& result);
void Multiplication(const Matrix& matA, const Matrix& matB, Matrix& result);
double Determinant(const Matrix& matA);
Matrix Transpose(const Matrix& matA);
Matrix Inverse(const Matrix& matA);
void inputMatrix(Matrix& mat);
void printMatrix(const Matrix& mat, bool flag);

int main()
{
    // declaring the input variable
    int choice;

    // do-while loop so that the menu is displayed at leats once
    do
    {
        cout << endl << "This is a program that performs matrix operations!" << endl;
        cout << "1: Addition" << endl;
        cout << "2: Subtraction" << endl;
        cout << "3: Multiplication" << endl;
        cout << "4: Determinant" << endl;
        cout << "5: Transpose" << endl;
        cout << "6: Inverse" << endl;
        cout << "7: Quit" << endl;
        cout << "Please enter your choice: ";
        
        // taking the user input

        cin >> choice;


        Matrix matA, matB, result;

        // taking two matrices to perform addition substraction and multiplication 

        if (choice >= 1 && choice <= 3) 
        {
            inputMatrix(matA);
            printMatrix(matA, false);
            inputMatrix(matB);
            printMatrix(matB, false);
        }
        
        // taking only one matrix as input to perform inverse, transpose and find det
        else if (choice >= 4 && choice <= 6) 
        {
            inputMatrix(matA);
            printMatrix(matA, false);
        }

        int det = 0;
        // switch case
        switch (choice)
        {
        case 1:
            Addition(matA, matB, result);
            printMatrix(result, true);
            break;
        case 2:
            Subtraction(matA, matB, result);
            printMatrix(result, true);
            break;
        case 3:
            Multiplication(matA, matB, result);
            printMatrix(result, true);
            break;
        case 4:
            det = Determinant(matA);
            cout << "The determinant is: " << det << endl;
            break;
        case 5:
            result = Transpose(matA);
            printMatrix(result, true);
            break;
        case 6:
            result = Inverse(matA);
            printMatrix(result, true);
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Enter Your Choice" << endl;
            break;
        }
    } // do while condition fails if the choice is 7
    while (choice != 7);
    return 0;
}

void inputMatrix(Matrix& mat)
{
    // taking the row and column values
    int rows, cols;
    // do while loop to take the input dimension is between 0-10
    do
    {
        cout << "Please enter the number of rows: ";
        cin >> rows;
    } while (rows <= 0 || rows >= 10);
    do
    {
        cout << "Please enter the number of cols: ";
        cin >> cols;
    } while (cols <= 0 || cols >= 10);
    

    // resizing the vector dimensions
    mat.resize(rows, vector<double>(cols, 0.0));

    cout << "Enter the matrix elements:" << endl;

    // entering the vector values

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cin >> mat[i][j];
        }
    }
}

void printMatrix(const Matrix& mat, bool flag)
{
    // if-else condition to check the flag value
    // if flag== false then  it is input matrix
    // else it is a result matrix
    // and appropriate print statements are printed
    if (!flag) 
    {
        cout << "Input matrix:" << endl;
    } 
    else 
    {
        cout << "Result matrix:" << endl;
    }

    // printing the vector
    for (const vector<double>& row : mat) 
    {
        for (double val : row) 
        
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void Addition(const Matrix& matA, const Matrix& matB, Matrix& result)
{
    // checking if both the vectors have the same dimensions to perform addition

    if(matA.size() != matB.size() || matA[0].size() != matB[0].size())
    {
		cout << "Both matrices must have the same dimension" << endl;
	}
    else
    {
        int rows = matA.size();
        int cols = matA[0].size();

        result.resize(rows, vector<double>(cols, 0.0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = matA[i][j] + matB[i][j];
        }
    }
    } 
}

void Subtraction(const Matrix& matA, const Matrix& matB, Matrix& result)
{
    // checking if both the vectors have the same dimensions to perform substraction

    if(matA.size() != matB.size() || matA[0].size() != matB[0].size())
    {
		cout << "Both matrices must have the same dimension" << endl;
	}
    else
    {
        int rows = matA.size();
        int cols = matA[0].size();

        result.resize(rows, vector<double>(cols, 0.0));

        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                result[i][j] = matA[i][j] - matB[i][j];
            }
        }
    }
}

void Multiplication(const Matrix& matA, const Matrix& matB, Matrix& result)
{
    // checking if cA == rB, condition that is required to perform matrix multiplication using 2d vectors
    if (matA[0].size() != matB.size())
	{
		cout << "Cannot perform multiplication operation as cA != rB" << endl;
	}
    else
    {

    
    int rowsA = matA.size();
    int colsA = matA[0].size();
    int colsB = matB[0].size();

    result.resize(rowsA, vector<double>(colsB, 0.0));

    for (int i = 0; i < rowsA; ++i) 
    {
        for (int j = 0; j < colsB; ++j) 
        {
            for (int k = 0; k < colsA; ++k) 
            {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    }
}

double Determinant(const Matrix& matA)
{
    int n = matA.size();


    // condition to check if the inputed matrix is a square or not.
    if (n != matA[0].size()) 
    {
        cout << "Matrix must be square for determinant calculation." << endl;
        return 0.0;
    }
    // checking if the input is 3x3
    if(n!=3 || matA[0].size() != 3)
    {
        cout << "Matrix A must have 3x3 dimension"<< endl;
        return -1;
    }

    double det = 0.0;
    for (int i = 0; i < n; ++i) 
    {
        Matrix submatrix(n - 1, vector<double>(n - 1, 0.0));
        for (int j = 1; j < n; ++j) 
        {
            for (int k = 0; k < n; ++k) 
            {
                if (k < i) 
                {
                    submatrix[j - 1][k] = matA[j][k];
                } 
                else if (k > i) 
                {
                    submatrix[j - 1][k - 1] = matA[j][k];
                }
            }
        }
        det += matA[0][i] * (submatrix[0][0]*submatrix[1][1] - submatrix[0][1]*submatrix[1][0]) * (i % 2 == 0 ? 1 : -1);
    }
    return det;
}
            

Matrix Transpose(const Matrix& matA)
{
    // determining the dimensions
    int rows = matA.size();
    int cols = matA[0].size();
    Matrix result(cols, vector<double>(rows, 0.0));

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            // swapping the row-col values
            result[j][i] = matA[i][j];
        }
    }

    return result;
}

Matrix Inverse(const Matrix& matA)
{
    // determining the dimensions
    int n = matA.size();
    Matrix result(n, vector<double>(n, 0.0));

    // if condition to check if the vector is a square 
    if (n != matA[0].size()) 
    {
        cout << "Matrix must be square for inversion and 3x3" << endl;
        return Matrix();
    }
    
    // Checking if the input is a 3x3 matrix
    if(n!=3 || matA[0].size() != 3)
    {
        cout << "Matrix A must have 3x3 dimension"<< endl;
        return Matrix();
    }
    // calling the determinant function
    double detA = Determinant(matA);
    if (detA == 0.0) {
        cout << "The inverse of the matrix does not exist." << endl;
        return result;
    }

    // calculating the inverse
    
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            Matrix submatrix(n - 1, vector<double>(n - 1, 0.0));
            for (int row = 0, subrow = 0; row < n; ++row) 
            {
                if (row == i) 
                {
                    continue;
                }
                for (int col = 0, subcol = 0; col < n; ++col) 
                {
                    if (col == j) 
                    {
                        continue;
                    }
                    submatrix[subrow][subcol] = matA[row][col];
                    ++subcol;
                }
                ++subrow;
            }
            result[j][i] = (submatrix[0][0]*submatrix[1][1] - submatrix[0][1]*submatrix[1][0]) / detA * ((i + j) % 2 == 0 ? 1 : -1);
        }
    }
    return result;
}
