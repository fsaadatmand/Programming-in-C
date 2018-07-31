/* 
 * Macro that gives a nonzero value if a character is an alphabetic character
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
