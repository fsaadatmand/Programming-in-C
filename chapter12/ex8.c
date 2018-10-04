/* 
 * 8. Write a macro IS_DIGIT that gives a nonzero value if a character is a
 * digit '0' through '9'. Use this macro in the definition of another macro
 * IS_SPECIAL, which gives a nonzero result if a character is a special
 * character; that is, not alphabetic and not a digit. Be certain to use the
 * IS_ALPHABETIC macro developed in exercise 7.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

#define IS_LOWER_CASE(c) (((c) >= 'a') &&  ((c) <= 'z'))
#define IS_UPPER_CASE(c) (((c) >= 'A') &&  ((c) <= 'Z'))
#define IS_ALPHABETIC(c) ((IS_LOWER_CASE(c)) || (IS_UPPER_CASE(c)))
#define IS_DIGIT(c) (((c) >= '0') && ((c) <= '9'))
#define IS_SPECIAL(c) ((!IS_ALPHABETIC(c)) && (!IS_DIGIT(c)))

int main(void) 
{
	char c = '$';

	if (IS_ALPHABETIC(c))
		printf("%c is an alphabetic character\n", c);
	else if (IS_DIGIT(c))
		printf("%c is a digit character\n", c);
	else if (IS_SPECIAL(c))
		printf("%c is a special character\n", c);

	return 0;
}
