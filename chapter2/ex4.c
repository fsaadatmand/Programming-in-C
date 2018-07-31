/* 
 * Program that substract the value 15 from 87 and displays the appropriate 
 * message at the terminal 
 */

#include <stdio.h>

int main(void) 
{
	int value1 = 87;
	int value2 = 15;
	int result;

	result = 87 - 15;

	printf("%i minus %i is %i\n", value1, value2, result);

	return 0;
}
