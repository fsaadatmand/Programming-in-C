/* 
 * Program to implement the sign function
 *
 * The nested if statment:
 * if ( expression 1 )
 * 		program statement 1
 * 	else
 * 		if ( expresion 2 )
 * 			program statement 2
 * 		else
 * 			program statement 3
 *
 * The else if Construct:
 * if ( expression 1 )
 * 		program statement 1
 * 	else if ( expression 2 )
 * 		program statement 2
 * 	else
 * 		program statement 3
 */

#include <stdio.h>

int main(void)
{
	int number, sign;

	printf("Please type in a number: ");
	scanf("%i", &number);

	if (number < 0)
		sign = -1;
	else if (number == 0)
		sign = 0;
	else               // Must be positive
		sign = 1;

	printf("sign = %i\n", sign);

	return 0;
}
