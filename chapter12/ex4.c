/* 
 * Macro that gives the maximum value amongst three numbers. 
 * By Faisal Saadatmand
 */

#include <stdio.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))  
#define MAX3(a,b,c) ((MAX(a,b) > (c)) ? (MAX(a,b)) : (c))

int main(void) 
{
	int x = 5, y = 7, z = 20;
	int max3value;

	max3value = MAX3(x + 16, y * y, z);

	printf("Maximum value for %i, %i, %i is %i\n", x, y, z, MAX3(x, y, z));
	printf("Result of MAX3 macro is %i\n", max3value);

	return 0;
}
