/* 
 * 2. Write a function called monthName() that takes as its argument a value of
 * type enum month (as defined in this chapter) and returns a pointer to a
 * character string containing the name of the month. In this way, you can
 * display the value of an enum month variable with a statement such as:
 *
 * 		printf ("%s\n", monthName(aMonth));
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* Define and declare enum month type */
enum month { January = 1, February, March, April, May, June,
	July, August, September, October, November, December };

/* Character string containing the name of the month */
char *months[] = { "January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November", "December" };

/* Function that returns pointer to the character string months[] */
char *monthName(enum month value)
{
	return months[value];  
}

int main(void) 
{
	char *monthName(enum month value);
	enum month aMonth;          /* declare aMonth variable as enum month type */

	aMonth = 11;      /* Assign a value from enum month type to aMonth variable */

	printf("%s\n", monthName(aMonth));

	return 0;
}
