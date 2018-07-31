/* 
 * Program to transpose array M with i rows, j columns into array N with j rows, i columns,
 * using functions.
 * By Faisal Saadatmand
 */

#include <stdio.h>

void transposeMatrix(int a[4][5], int b[5][4])
{
	int row, column;

	for (column = 0; column < 5 ; ++column)
		for (row = 0; row < 4; ++row)
			b[column][row] = a[row][column];

}

void displayMatrix(int matrix [][4])
{
	int row, column;

	for (row = 0; row < 5; ++row) {
		for (column = 0; column < 4; ++column)
			printf("%5i", matrix[row][column]);
		printf("\n");
	}
}

int main (void)
{
	int N[5][4];
	int M[4][5] = { { 5, 6, 12, 2, 24 },
					{ 3, 33, 5, 11,14 },
					{ 10, 3, 8, 20, 7 },
					{ 41, 82, 75, 55, 67 } };
	
	void transposeMatrix(int a[4][5], int b[5][4]);
	void diplayMatrix(int matrix[][5]);

	transposeMatrix(M, N);
	displayMatrix(N);

	return 0;
}
