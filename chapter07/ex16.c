 /*
 * 16. Modify Program 7.14 so that the user can convert any number of integers.
 * Make provision for the program to terminate when a zero is typed in as the
 * value of number to be converted.
 *
 * By Faisal Saadatmand
 */
 
#include <stdio.h>
#include <stdbool.h>

#define SIZE 64 /* see chapter 14. The #define Statement */

/* globals */
int gConvertedNumber[SIZE];
long int gNumberToConvert;
int gBase;
int gDigit = 0;

/* functions */
void getNumberAndBase(void);
void convertNumber(void);
void displayConvertedNumber(void);
void resetVariables(void);

void getNumberAndBase(void)
{
	printf("Number to be converted? ");
	scanf("%li", &gNumberToConvert);
	if (gNumberToConvert == 0) /* user entered 0? */
		return; /* exit early */
	while (true) {
		printf("Base? ");
		scanf("%i", &gBase);
		if (gBase >= 2 && gBase <= 16) /* exit loop if base is within range*/
			break;
		printf("Invalid base - must be between 2 and 16\n");
	}
}
	
void convertNumber(void)
{
	do {
		gConvertedNumber[gDigit] = gNumberToConvert % gBase;
		++gDigit;
		gNumberToConvert /= gBase;
	} while (gNumberToConvert != 0);
}

void displayConvertedNumber(void)
{
	const char baseDigits[16] =
	{ '0', '1', '2', '3', '4', '5', '6', '7',
      '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	int nextDigit;

	printf("Converted number = ");

	for (--gDigit; gDigit >= 0; --gDigit) {
		nextDigit = gConvertedNumber[gDigit];
		printf("%c", baseDigits[nextDigit]);
	}
	printf("\n");
}

/* resetVariables: clear global variables */
void resetVariables(void)
{
	int i;

	gNumberToConvert = gBase = gDigit = 0;
	for (i = 0; i < SIZE; ++i)
		gConvertedNumber[i] = 0;
}

int main(void)
{
	while (true) { /* repeat until entered number is 0 */
		getNumberAndBase();
		if (gNumberToConvert == 0)
			break;
		convertNumber();
		displayConvertedNumber();
		resetVariables(); /* important, otherwise the old values will persist */
	}
	return 0;
}
