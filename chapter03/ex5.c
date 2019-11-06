/*
 * 5. What output would you expect from the following program?
 * 
 *    Answer: d = d
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	char c, d;

	c = 'd';
	d = c;
	printf("d = %c\n", d);

	return 0;
}
