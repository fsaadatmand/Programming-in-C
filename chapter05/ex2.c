/*
 * 2. Write a program that asks the user to type in two integer values at the
 * terminal. Test these two numbers to determine if the first is evenly
 * divisible by the second, and then display an appropriate message at the
 * terminal.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int number1, number2;

	printf("Type in two digits:\n");
	scanf("%i %i", &number1, &number2);

	if (number1 % number2 == 0)
		printf("%i is evenly divisible by %i\n", number1, number2);
	else
		printf("%i is NOT evenly divisible by %i\n", number1, number2);

	return 0;
}
