/* 
 * Using comments in a program. This program adds two integer values
 * and displays the results
 */

#include <stdio.h>

int main(void) 
{
	// Declare variables
	int value1, value2, sum;

	// Assign values and calculate their sum
	value1 = 50;
	value2 = 25;

	sum = value1 + value2;

	// Display the result
	printf("The sum of %i and %i is %i\n", value1, value2, sum);

	return 0;
}
