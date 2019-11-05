/*
 * 15. Modify Program 7.14 so that the user is asked again to type in the value
 * of the base if an invalid base is entered. The modified program should
 * continue to ask for the value of the base until a valid response is given.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

/* globals */
int gConvertedNumber[64];
long int gNumberToConvert;
int gBase;
int gDigit = 0;

/* functions */
void getNumberAndBase(void);
void convertNumber(void);
void displayConvertedNumber(void);

void getNumberAndBase(void)
{
	bool repeat;

	printf("Number to be converted? ");
	scanf("%li", &gNumberToConvert);

	repeat = true;
	while (repeat) {
		printf("Base? ");
		scanf("%i", &gBase);

		if (gBase >= 2 && gBase <= 16)
			repeat = false;

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

int main(void)
{
	getNumberAndBase();
	convertNumber();
	displayConvertedNumber();

	return 0;
}
