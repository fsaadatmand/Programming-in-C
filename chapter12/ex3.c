/*
 * 3. Define a macro MIN that gives the minimum of two values. Then write a
 * program to test the macro definition.
 *
 * By Faisal Saadatmand
 */


#include <stdio.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b)) 

int main(void) 
{

	int x = 5, y = 7;

	printf("%i\n", MIN(x, y));

	return 0;
}
