/* 
 * 12. A matrix M with i rows, j columns can be transposed into a matrix N
 * having j rows and i columns by simply setting the value of Na,b equal to the
 * value of Mb,a for all relevant values of a and b.
 *
 *	 a. Write a function transposeMatrix() that takes as an argument a 4 × 5
 *	 matrix and a 5 × 4 matrix. Have the function transpose the 4 × 5 matrix
 *	 and store the results in the 5 × 4 matrix. Also write a main() routine to
 *	 test the function.
 *
 *	 b. Using variable-length arrays, rewrite the transposeMatrix() function
 *	 developed in exercise 12a to take the number of rows and columns as
 *	 arguments, and to transpose the matrix of the specified dimensions.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* functions */
void transposeMatrix(int [][5], int [][4]);
void diplayMatrix(int [][5]);

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

	transposeMatrix(M, N);
	displayMatrix(N);

	return 0;
}
