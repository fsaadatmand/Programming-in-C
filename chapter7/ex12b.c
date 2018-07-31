/* 
 * Program to transpose array M with i rows, j columns into array N with j rows, i columns,
 * using functions and variable-length multidimencional arrays.
 * By Faisal Saadatmand
 */

#include <stdio.h>

void transposeMatrix(int nRows, int nColumns, int a[nRows][nColumns], int b[nColumns][nRows])
{
	int row, column;

	for (column = 0; column < nColumns ; ++column)
		for (row = 0; row < nRows; ++row)
			b[column][row] = a[row][column];
}

void displayMatrix (int nRows, int nColumns, int matrix[nRows][nColumns])
{
	int row, column;

	for (row = 0; row < nRows; ++row) {
		for (column = 0; column < nColumns; ++column)
			printf("%5i", matrix[row][column]);
		printf("\n");
	}
}

int main(void)
{
	int M[4][5] = { { 5, 6, 12, 2, 24 },
					{ 3, 33, 5, 11,14 },
					{ 10, 3, 8, 20, 7 },
					{ 41, 82, 75, 55, 67 } };
	int N[5][4];

	void transposeMatrix(int nRows, int nColumns, int a[nRows][nColumns],
                          int b[nColumns][nRows]);
	void diplayMatrix(int nRows, int nColumns, int matrix[nRows][nColumns]);

	transposeMatrix(4, 5, M, N);
	displayMatrix(5, 4, N);

	return 0;
}
