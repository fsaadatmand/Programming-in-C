/* Program to test if a digit is evenly divisable by another digit */

#include <stdio.h>

int main(void)
{
	int number1, number2;

	printf("Type in two digits:\n");
	scanf("%i %i", &number1, &number2);

	if (number1 % number2 == 0)
		printf("%i is evely divisable by %i\n", number1, number2);
	else if (number1 % number2 != 0)
		printf("%i is NOT evenly divisable by %i\n", number1, number2);

	return 0;
}
