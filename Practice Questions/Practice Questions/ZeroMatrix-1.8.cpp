#include <iostream>
using namespace std;

// write an algorithm such that if an element in a MxN matrix is 0, its entire row and column are set to 0

// nullify the row, function takes the matrix, number of columns, and the row to nullify
void nullifyRow(int** matrix, int N, int row)
{
	for (int i = 0; i < N; i++)
	{
		matrix[row][i] = 0;
	}
}


// nullify the column, function takes the matrix, number of rows, and the column to nullify
void nullifyColumn(int** matrix, int M, int column)
{
	for (int i = 0; i < M; i++)
	{
		matrix[i][column] = 0;
	}
}

// nulify the matrix, function takes the matrix, number of rows and columns
void nullifyMatrix(int** matrix, int M, int N)
{
	// boolean to check if the first row has a 0
	bool firstRow = false;

	// check the first row of the matrix
	for (int i = 0; i < N; i++)
	{
		if (matrix[0][i] == 0)
		{
			firstRow = true;
			break;
		}
	}

	// check the rest of the matrix
	for (int i = 1; i < M; i++) // start at row 1 since we already checked the first row
	{
		bool nullifyThisRow = false;
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == 0)
			{
				// if we find a zero, we know we can set the first row of that column to 0
				matrix[0][j] = 0;
				// we found a zero in this row, lets set the boolean to true
				nullifyThisRow = true;
			}
		}
		if (nullifyThisRow)
		{
			nullifyRow(matrix, N, i);
		}
	}

	// check the columns based off the columns we set to 0 in the first row in the previous step
	for (int i = 0; i < N; i++)
	{
		if (matrix[0][i] == 0)
		{
			nullifyColumn(matrix, M, i);
		}
	}

	// now we nullify the first row if it had any zeros to start with
	if (firstRow)
	{
		nullifyRow(matrix, N, 0);
	}

}

// print matrix
void printMatrix(int** matrix, int M, int N)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


int main()
{
	int M;
	int N;

	// ask user for size of matrix
	cout << "Enter the number of rows in the matrix: " << endl;
	cin >> M;
	cout << "Enter the number of columns in the matrix: " << endl;
	cin >> N;

	// create matrix
	int ** matrix = new int* [M];
	for (int i = 0; i < M; i++)
	{
		matrix[i] = new int [N];
	}

	// user inputs values
	cout << "Enter values for the matrix: " << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "Matrix before: " << endl;
	printMatrix(matrix, M, N);
	nullifyMatrix(matrix, M, N);
	cout << "Matrix after: " << endl;
	printMatrix(matrix, M, N);

	return 0;
}