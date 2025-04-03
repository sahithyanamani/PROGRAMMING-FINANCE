#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <sstream>
#include <typeinfo>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

void Addition(double[][10], double[][10], int, int, int, int);
void Subtraction(double[][10], double[][10], int, int, int, int);
void Multiplication(double[][10], double[][10], int, int, int, int);
double Determinant(double[][10], int, int);
void Transpose(double[][10], int, int);
void Inverse(double[][10], int, int);
void inputMatrix(double[][10], int *, int *);
void printMatrix(double[][10], int, int, bool);

int main()
{
	// declaring the choice variable
	int choice;

	// do-while loop so that the menu is displayed at leats once
	do
	{

		cout << endl<< "This is a program that performs matrix operations!" << endl;
		cout << "1: Addtion" << endl;
		cout << "2: Subtraction" << endl;
		cout << "3: Multiplication" << endl;
		cout << "4: Determinant" << endl;
		cout << "5: Transpose" << endl;
		cout << "6: Inverse" << endl;
		cout << "7: Quit" << endl;
		cout << "Please enter your choice: ";
		// taking the user input
		cin >> choice;

		int rA = 0, cA = 0, rB = 0, cB = 0;

		// initialising the 2d arrays with zeroes
		double matA[10][10] = {{0}};
		double matB[10][10] = {{0}};

		// taking two matrices to perform addition substraction and multiplication 


		if (choice >= 1 && choice <= 3)
		{
			inputMatrix(matA, &rA, &cA);
			printMatrix(matA, rA, cA, false);
			inputMatrix(matB, &rB, &cB);
			printMatrix(matB, rB, cB, false);
		}
		// taking only one matrix as input to perform inverse, transpose and find det
		else if (choice >= 4 && choice <= 6)
		{
			inputMatrix(matA, &rA, &cA);
			printMatrix(matA, rA, cA, false);
		}

		// switch case

		switch (choice)
		{

		case 1:
			Addition(matA, matB, rA, cA, rB, cB);
			break;
		case 2:
			Subtraction(matA, matB, rA, cA, rB, cB);
			break;
		case 3:
			Multiplication(matA, matB, rA, cA, rB, cB);
			break;
		case 4:
			Determinant(matA, rA, cA);
			break;
		case 5:
			Transpose(matA, rA, cA);
			break;
		case 6:
			Inverse(matA, rA, cA);
			break;
		case 7:
			exit(0);
			break;
		default:
			cout << "Enter Your Choice" << endl;
			break;
		}

	} 
	// do while condition fails if the choice is 7
	while (choice != 7);
	return 0;
}

void inputMatrix(double A[][10], int *r, int *c)
{
	 // do while loop to take the input dimension is between 0-10
	do
	{
		cout << "Please enter row dim: ";
		cin >> *r;
	} while (*r <= 0 || *r > 10);

	do
	{
		cout << "Please enter column dim: ";
		cin >> *c;
	} while (*c <= 0 || *c > 10);

	cout << "Enter the array elements" << endl;

	// entering the matrix- 2d array values

	for (int i = 0; i < *r; i++)
	{
		for (int j = 0; j < *c; j++)
		{
			cin >> A[i][j];
		}
	}
}

void printMatrix(double M[][10], int r, int c, bool flag)
{
	
	// if-else condition to check the flag value
    // if flag== false then  it is input matrix
    // else it is a result matrix
    // and appropriate print statements are printed
	if (!flag)
	{
		cout << "Input matrix: " << endl;
	}
	else
	{
		cout << "Result matrix: " << endl;
	}
	// printing the matrix-array values
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

void Addition(double matA[][10], double matB[][10], int rA, int cA, int rB, int cB)
{
	// checking if both the matrices have the same dimensions to perform addition
	if (rA != rB || cA != cB)
	{
		cout << "Both matrices must have the same dimensions" << endl;
	}
	else
	{
		double matC[10][10] = {{0}};
		for (int i = 0; i < rA; i++)
		{
			for (int j = 0; j < cA; j++)
			{
				matC[i][j] = matA[i][j] + matB[i][j];
			}
		}
		printMatrix(matC, rA, cA, true);
	}
}

void Subtraction(double matA[][10], double matB[][10], int rA, int cA, int rB, int cB)
{
	// checking if both the matrices have the same dimensions to perform substraction
	if (rA != rB || cA != cB)
	{
		cout << "Both matrices must have the same dimension" << endl;
	}
	else
	{
		double matC[10][10] = {{0}};
		for (int i = 0; i < rA; i++)
		{
			for (int j = 0; j < cA; j++)
			{
				matC[i][j] = matA[i][j] - matB[i][j];
			}
		}
		printMatrix(matC, rA, cA, true);
	}
}

void Multiplication(double matA[][10], double matB[][10], int rA, int cA, int rB, int cB)
{
	// checking if cA == rB, condition that is required to perform matrix multiplication using 2d matrices
	if (cA != rB)
	{
		cout << "Cannot perform multiplication operation as cA != rB" << endl;
	}
	else
	{
		double matC[10][10] = {{0}};
		for (int i = 0; i < rA; i++)
		{
			for (int j = 0; j < cB; j++)
			{
				for (int k = 0; k < cA; k++)
				{
					matC[i][j] += matA[i][k] * matB[k][j];
				}
			}
		}
		printMatrix(matC, rA, cB, true);
	}
}

double Determinant(double matA[][10], int rA, int cA)
{
	double determinant = 0;
	// condition to check if the inputed matrix is of 3x3
	if (rA != 3 || cA != 3)
	{
		cout << "r and c must be of size 3" << endl;
	}
	else
	{
		determinant = matA[0][0] * (matA[1][1] * matA[2][2] - matA[1][2] * matA[2][1]) -
					  matA[0][1] * (matA[1][0] * matA[2][2] - matA[1][2] * matA[2][0]) +
					  matA[0][2] * (matA[1][0] * matA[2][1] - matA[1][1] * matA[2][0]);
		cout << "The determinant is: " << determinant << endl;
	}
	return determinant;
}

void Transpose(double matA[][10], int rA, int cA)
{
	double matC[10][10] = {{0}};
	for (int i = 0; i < rA; i++)
	{
		for (int j = 0; j < cA; j++)
		{
			matC[j][i] = matA[i][j];
		}
	}
	printMatrix(matC, cA, rA, true);
}

void Inverse(double matA[][10], int rA, int cA)
{
	// if condition to check if the vector is a square ad has 3x3
	if (rA != 3 || cA != 3)
	{
		cout << "r and c must be of size 3" << endl;
	}
	else
	{
		double determinant = Determinant(matA, rA, cA);
		if (determinant == 0)
		{
			cout << "The inverse of the matrix does not exist." << endl;
		}
		else
		{
			double dd = 1 / determinant;
            double matC[10][10] = {{0}};
        
             
			for(int r = 0; r < 3; r++)
			{
        		for(int c = 0; c < 3; c++)
				{
                    
            		matC[r][c] = ((matA[(c+1)%3][(r+1)%3] * matA[(c+2)%3][(r+2)%3]) - (matA[(c+1)%3][(r+2)%3] * matA[(c+2)%3][(r+1)%3]))*dd;
        		}
                
			}
			printMatrix(matC, 3, 3, true);
		}
	}
}
