/* 
 * Program to determine if a number is even or odd 
 *
 * Th if-else Construct:
 * if (expresion)
 * 		program statment 1
 * 	else
 * 		program statments 2
 */

#include <stdio.h>

int main(void)
{
	int number_to_test, remainder;

	printf("Enter your number to be tested.: ");
	scanf("%i", &number_to_test);

	remainder = number_to_test % 2;

	if (remainder == 0)
		printf("The number is even.\n");
	if (remainder != 0)
		printf("The number is odd.\n");

	return 0;
}



