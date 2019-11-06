/* 
 * 14. Rewrite the functions developed in the last four exercises to use global
 * variables instead of arguments. For example, the preceding exercise should
 * now sort a globally defined array.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>


/* globals */
int M[4][5] = { { 5, 6, 12, 2, 24 },
				{ 3, 33, 5, 11,14 },
				{ 10, 3, 8, 20, 7 },
				{ 41, 82, 75, 55, 67 } };
int nRows = 4;
int nColumns = 5;

/* functions */
void transposeMatrix(int a[nRows][nColumns], int b[nColumns][nRows]);
void diplayMatrix(int matrix[nRows][nColumns]);

void transposeMatrix( int a[nRows][nColumns], int b[nColumns][nRows])
{
	int row, column;

	for (column = 0; column < nColumns ; ++column)
		for (row = 0; row < nRows; ++row)
			b[column][row] = a[row][column];
}

void displayMatrix(int matrix[nRows][nColumns])
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
	int N[nColumns][nRows];

	printf("\nMatrix M\n");
	displayMatrix(M);
	transposeMatrix(M, N);
	printf("\nMatrix N - transposition of M\n");
	displayMatrix(N);
	printf("\n");

	return 0;
}
