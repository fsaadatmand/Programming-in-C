/* 
 * Program that accepts two integer values typed in by the user and
* Display the result of dividing the first integer by the second, to three-
* decimal-place accuracy.  It also checks for division by zero.
*/

#include <stdio.h>

int main(void)
{
	int number1, number2;
	float result;

	printf("Type in two digits:\n");
	scanf("%i %i", &number1, &number2);

	if (number2 == 0)
		printf("Division by zerp");
	else
		result = (float) number1 / number2;

	printf("%i divided by %i is %.3f\n", number1, number2, result); 

	return 0;
}
