/* Program 4.4, asking the user for input -- replace for with while loop  */

#include <stdio.h>

int main(void)
{
	int n = 1, number, triangularNumber;

	printf("Waht triangular number do you want? ");
	scanf("%i", &number);

	triangularNumber = 0;

	while (n <= number) {
		triangularNumber += n;
		++n;
	}

	printf("Triangular number %i is %i\n", number, triangularNumber);
	
	return 0;
}
