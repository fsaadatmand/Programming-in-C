/* Macro that gives the minimum of two values */

#include <stdio.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b)) 

int main(void) 
{

	int x = 5, y = 7;
	int minValue;
	long int z = 2E2;

	minValue = MIN(x, y);

	printf("%i\n", minValue);
	printf("%i\n", z);

	return 0;
}
