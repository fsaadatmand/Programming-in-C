/* Program (4.5) Using nested loops -- replace for with while loop */

#include <stdio.h>

int main(void)
{
	int n = 1, number, number2, triangularNumber, counter;

	printf("How many triangular numbers to calculate? ");
	scanf("%i", &number2);

	counter = 1;

	while (counter <= number2) {
		printf("What is the value of triangular number %i? ", counter);
		scanf("%i", &number);

		triangularNumber = 0;

		while (n <= number) {
			triangularNumber += n;
			++n;
		}

		printf("Triangular number %i is %i\n\n", number, triangularNumber);

		++counter;
	}

	return 0;
}

