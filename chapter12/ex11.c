/* 
 * 11. Test the system library functions that are equivalent to the macros you
 * developed in the preceding three exercises. The library functions are called
 * isupper, isalpha, and isdigit. You need to include the system header file
 * <ctype.h> in your program in order to use them.
 *
 * Also see chapter 9 bonus exercises.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	char c = 'A';

	if (isalpha(c))
		if (isupper(c))
			printf("%c is an uppercase alphabetic character\n", c);
		else
			printf("%c is a lowercase alphabetic character\n", c);
	else if (isdigit(c))
		printf("%c is a digit character\n", c);
	else if (!isalpha(c) && !isdigit(c))
		printf("%c is a special character\n", c);

	return 0;
}
