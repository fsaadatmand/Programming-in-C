/* 
 * 6. Write a macro IS_UPPER_CASE that gives a nonzero value if a character is
 * an uppercase letter.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

#define IS_UPPER_CASE(c) (((c) >= 'A') && ((c) <= 'Z'))

int main(void) 
{
	char c = 'R';

	if (IS_UPPER_CASE(c))
		printf("%c is uppercase\n", c);
	else
		printf("%c is lowercase\n", c);

	return 0;
}
