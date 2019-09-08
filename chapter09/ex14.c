/*
 * 14. Write a function called intToStr() that converts an integer value into a
 * character string. Be certain the function handles negative integers
 * properly.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

void intToStr(int intValue, char string[])
{
	int i, j = 0, rightNumber;
	char reversedString[40];
	bool negativeNumber = false;
	
	if (intValue < 0) {                  /* detect negative value integers */
		intValue = -intValue;
		negativeNumber = true;
	}
	
	for (i = 0; intValue != 0; ++i) {    /* convert intValue in reverse */
		rightNumber = intValue % 10;     /* extract numbers from the right */
		intValue /= 10;
		reversedString[i] = rightNumber + '0';
	}

	if (negativeNumber) {                /* insert minus sign in string[0] */
		string[j] = '-';
		++j;
	}

	--i;                                 /* start from the correct end position */ 
	while (i >= 0) {                     /* reverse the character string */
		string[j] = reversedString[i];
		--i;
		++j;
	}

	string[j] = '\0';                    /* insert null character at the end */
}

int main(void) 
{
	void intToStr(int intValue, char string[]);

	int intValue;
	char str[40];

	printf("Enter integer value: ");
	scanf("%i", &intValue);

	intToStr(intValue, str);
	printf("%s\n", str);

	return 0;
}
