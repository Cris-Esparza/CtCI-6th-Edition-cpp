#include <iostream>
using namespace std;

// Problem 1.7 Rotate a matrix by 90' clockwise ( or anticlockwise).

// first approach is to take the transpose of the matrix (swap rows with columns)
void transpose(int** matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (i != j)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
}

// clockwise rotation
void clockwiseRotation(int* row, int N)
{
	for (int i = 0; i < N / 2; i++)
	{
		swap(row[i], row[N - i - 1]);
	}
}

void rotation1(int** matrix, int N)
{
	//transpose matrix
	transpose(matrix, N);

	// reverse each row
	for (int i = 0; i < N; i++)
	{
		clockwiseRotation(matrix[i], N);
	}
}

// Second approach is rotating elements layer by layer
// counter-clockwise rotation
void rotation2(int** matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N - i - 1; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][N - i - 1];
			matrix[j][N - i - 1] = matrix[N - i - 1][N - j - 1];
			matrix[N - i - 1][N - j - 1] = matrix[N - j - 1][i];
			matrix[N - j - 1][i] = temp;
		}
	}
}

void printMatrix(int** matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int N;
	cout << "Enter N for NxN matrix:";
	cin >> N;
	int** matrix = new int* [N];
	for (int i = 0; i < N; ++i) {
		matrix[i] = new int[N];
	}

	// user inputs matrix values
	cout << "Enter values for each cell in the matrix: " << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << "Original matrix: " << endl;
	printMatrix(matrix, N);

	cout << "Rotated matrix by 90 (clockwise):\n";
	rotation1(matrix, N);
	printMatrix(matrix, N);

	cout << "Rotated matrix again by 90(anticlockwise):\n";
	rotation2(matrix, N);
	printMatrix(matrix, N);

	return 0;
}
