/*
 * Bonus exercise: Program to extract and display each typed-in digit of the
 * integer in English:
 *
 * 		932 -> nine three two
 *
 * By Faisal Saadatmand
  */

#include <stdio.h>
#include <ctype.h>

#define LENGTH 100 

int main(void)
{
	char number[LENGTH];
	char *p, *words[] = { "zero", "one", "two", "three", "four",
					      "five", "six", "seven", "eight", "nine" };
							  
	printf("Enter a number: ");
	scanf("%99s", number);

	for (p = number; p && *p; ++p) {
		if (!isdigit(*p)) {
			printf("\nError: %c is not a digit", *p);
			break;
		}
		printf("%s ", words[*p - '0']);
	}
	printf("\n");

	return 0;
}

