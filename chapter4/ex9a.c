/* 
 * Program (4.2) to calculate the  200th triangular number
 * Introduction of the for statement -- Replace for with while loop 
 * */

#include <stdio.h>

int main(void)
{
	int n, triangularNumber;

	triangularNumber = 0;
	n = 1;

	while (n <= 200) {	
		triangularNumber = triangularNumber + n;
		++n;
	}

	printf("The 200th tiangular number is %i\n", triangularNumber);

	return 0;
}
