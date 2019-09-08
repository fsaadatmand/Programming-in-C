/* 
 * 16. Modify Program 7.14 so that the user can convert any number of integers.
 * Make provision for the program to terminate when a zero is typed in as the
 * value of number to be converted.
 * By Faisal Saadatmand
 */

#include <stdio.h>

int         convertedNumber[16];
long int    numberToConvert;
int         base;
int         digit = 0;

void getNumberAndBase(void)
{
	printf("Number to be converted? ");
	scanf("%li", &numberToConvert);

	printf("Base? ");
	scanf("%i", &base);

	if (base < 2 || base > 16)
		do {
			printf("Invalid base - must be between 2 and 16\n");
			printf("Base? ");
			scanf("%i", &base);
		} while (base < 2 || base > 16);
}
	
void convertNumber(int base)
{
	do {
		convertedNumber[digit] = numberToConvert % base;
		++digit;
		numberToConvert /= base;
	} while (numberToConvert != 0);
}

void twosComplement(void)
{
	int i, remainder = 1;

	for (i = 15; i >= 0; --i) 
		printf("%i", convertedNumber[i]);
	printf("\n"); 

	for (i = 15; i >= 0; --i)                 /* invert binary number */
		if (convertedNumber[i] == 0) 
			convertedNumber[i] = 1;
		else if (convertedNumber[i] == 1)
			convertedNumber[i] = 0;

	for (i = 15; i >= 0; --i) 
		printf("%i", convertedNumber[i]);
	
	printf("\n"); 

	for (i = 0; i <= digit; ++i)              /* add 1 to binary number */
		if (convertedNumber[i] == 0 && remainder == 1) {
			convertedNumber[i] = 1;
			remainder = 0;
			break;
		} else if (convertedNumber[i] == 1 && remainder == 0) {
			convertedNumber[i] = 1;
			remainder = 0;
		} else if (convertedNumber[i] == 1 && remainder == 1) {
			convertedNumber[i] = 0;
			remainder = 1;
		} else
			convertedNumber[i] = 0;

	for (i = 15; i >= 0; --i) 
		printf("%i", convertedNumber[i]);

	printf("\n"); 
	printf("%i\n", digit);
}

long int x_to_the_n(int x, int n)
{
	int result = 1;

	while (n > 0) {
		result *= x;
		--n;
	}

    return result;
}

int arraySum(int a[], int n)
{
	int i, sum = 0;

	for (i = 0; i < n; ++i)
		sum += a[i];

	return sum;
}

void binaryToBase10(void)
{
	int array [8], i;

	for (i = 0; i <= 8; ++i)  
		array [i] = convertedNumber[i] * x_to_the_n(2, i);

	numberToConvert = arraySum(array, 8);
}

void displayConvertedNumber(void)
{
	int         nextDigit;
	const char  baseDigits[16] =
	                         { '0', '1', '2', '3', '4', '5', '6', '7',
                               '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	printf("Converted number = ");

	for (--digit; digit >= 0; --digit) {
		nextDigit = convertedNumber[digit];
		printf("%c", baseDigits[nextDigit]);
	}
	
	printf("\n");
}

int main(void)
{
	void        getNumberAndBase(void), convertNumber(int base), 
				twosComplement(void), binaryToBase10(void),
				displayConvertedNumber(void);

	long int    x_to_the_n(int x, int n);
	int         arraySum(int a[], int n); 

	getNumberAndBase();
	if (numberToConvert == 0)                   /* terminate programme when 0
												   is entered for the number 
												   to convert */
		return 1;
	if (base == 10)                             /* exclude base 10 from the
												   conversion algorithm */
		printf("Converted number = %li\n", numberToConvert);
	else if (numberToConvert < 0) {             /* handle negative integer
												   input */
		numberToConvert = -numberToConvert;
		convertNumber(2);                                        
		twosComplement();
		binaryToBase10();
		if (base != 2) {                        /* exclude base 2 from 
												   conversion back to decimal */
			digit = 0;
			convertNumber(base);
			displayConvertedNumber();
		} else 
			displayConvertedNumber();        
	} else {
		convertNumber(base);
		displayConvertedNumber();
	}

	return 0;
}
