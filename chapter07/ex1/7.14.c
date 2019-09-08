/* Using multidimensional arrays and functions with variable-length arrays */

#include <stdio.h>

int main(void) 
{
	void scalarMultiply(int nRows, int nColumns, int matrix[nRows][nColumns], int scalar);
	void displayMatrix(int nRows, int nColumns, int matrix[nRows][nColumns]);
	
	int sampleMatrix[3][5] = 
	{
		{ 7, 16, 55, 13, 12 },
		{ 12, 10, 52, 0, 7 },
		{ -2, 1, 2, 4, 9 }
	};

	printf("Original matrix:\n");
	displayMatrix(3, 5, sampleMatrix);

	scalarMultiply(3, 5, sampleMatrix, 2);
	printf("\nMultiplied by 2:\n");
	displayMatrix(3, 5, sampleMatrix);

	scalarMultiply(3, 5, sampleMatrix, -1);
	printf("\nThen Multiply by -1:\n");
	displayMatrix(3, 5, sampleMatrix);

	return 0;
}

/* Functions to multiplay a multidimensional array by a scalar */
void scalarMultiply(int nRows, int nColumns, int matrix[nRows][nColumns], int scalar)
{
	int row, column;

	for (row = 0; row < nRows; ++row)
		for (column = 0; column < nColumns; ++column)
			matrix[row][column] *= scalar;
}

/* function to display a multidimensional array */
void displayMatrix(int nRows, int nColumns, int matrix[nRows][nColumns])
{
	int row, column;

	for (row = 0; row < nRows; ++row) {
		for (column = 0; column < nColumns; ++column)
			printf("%5i", matrix[row][column]);
	
		printf("\n");
	}
}

