/* 
 * 3. Write a program that accepts two integer values typed in by the user.
 * Display the result of dividing the first integer by the second, to three-
 * decimal-place accuracy. Remember to have the program check for division by
 * zero.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int number1, number2;
	float result;

	printf("Type in two integers:\n");
	scanf("%d %d", &number1, &number2);

	if (number2 == 0) {
		printf("Division by zero");
		return -1;
	}

	result = (float) number1 / number2;

	printf("%i divided by %i is %.3f\n", number1, number2, result); 

	return 0;
}
