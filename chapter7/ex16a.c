/* 
 * Program to convert any integer to another base using global variables.
 * The program will ask for the number, base as well as the bit representation.
 * For negative values, a value of zero for a number will terminate the program.
 * By Faisal Saadatmand
 */

#include <stdio.h>

int              convertedNumber[32];
long long int    numberToConvert;
int              base, digit, numberOfBits;

void getNumberAndBase(void)
{
	printf("Number to be converted? ");
	scanf("%lli", &numberToConvert);

	printf("Base? ");
	scanf("%i", &base);

	if (base < 2 || base > 16) {                         /* issue: a value that is
															not a number in this range will cause an infinit loop */
		do {
			printf("Invalid base - must be between 2 and 16\n");
			printf("Base? ");
			scanf("%i", &base);
		} while (base < 2 || base > 16);
	}

	if (numberToConvert < 0 && base != 10) {
		do {
			printf("Representation? (4, 8, 16, or 32-bit) ");
			scanf("%i", &numberOfBits);

			switch (numberOfBits) {
			case 4:
				printf("4-bit represention\n");
				break;
			case 8:
				printf("8-bit representation\n");
				break;
			case 16:
				printf("16-bit representation\n");
				break;
			case 32:
				printf("32-bit representation\n");
				break;
			default:
				printf("Invalid input\n");
				numberOfBits = 0;
				break;
			}
		} while (numberOfBits == 0);
	}
}
	
void convertNumber(int base)
{
	digit = 0;           /* it's a good idea to reset the value 
							locally since the functions is called 
							multiple of times */
	do {
		convertedNumber[digit] = numberToConvert % base;
		++digit;
		numberToConvert /= base;
	} while (numberToConvert != 0);
}

void twosComplement(void)
{
	int i, remainder = 1;

	for (i = numberOfBits - 1; i >= 0; --i)                        /* invert binary number */
		if (convertedNumber[i] == 0) 
			convertedNumber[i] = 1;
		else
			convertedNumber[i] = 0;

	for (i = 0; i <= digit; ++i)                                   /* add 1 to binary number */
		if (convertedNumber[i] == 0 && remainder == 1) {
			convertedNumber[i] = 1;
			remainder = 0;
			break;                                                 /* optimises algorithm */
		} else if (convertedNumber[i] == 1 && remainder == 0) {
			convertedNumber[i] = 1;
			remainder = 0;
		} else if (convertedNumber[i] == 1 && remainder == 1) {
			convertedNumber[i] = 0;
			remainder = 1;
		} else
			convertedNumber[i] = 0;
}

long long int x_to_the_n(int x, int n)
{
	long long int result = 1LL;

	while (n > 0) {
		result *= x;
		--n;
	}

    return result;
}

long long int arraySum(long long int a[], int n)
{
	int i; 
	long long int sum = 0;

	for (i = 0; i < n; ++i)
		sum += a[i];

	return sum;
}

void binaryToBase10(void)
{
	int i;
	long long int array[numberOfBits];

	for (i = 0; i <= numberOfBits - 1; ++i) 
		array[i] = convertedNumber[i] * x_to_the_n(2, i);

	numberToConvert = arraySum(array, numberOfBits);
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
	void             getNumberAndBase(void), convertNumber(int base), twosComplement(void), 
		             binaryToBase10(void), displayConvertedNumber(void);
	long long int    x_to_the_n(int x, int n), arraySum(long long int a[], int n); 

	getNumberAndBase();
	if (numberToConvert == 0)                                       /* terminate programme when 0 is entered for the number to convert */
		return 1;
	else if (base == 10)                                            /* exclude base 10 from the conversion algorithm */
		printf("Converted number = %lli\n", numberToConvert);
	else if (numberToConvert < 0) {                                 /* handles negative integer input */
		numberToConvert = -numberToConvert;
		convertNumber(2);                                        
		twosComplement();
		binaryToBase10();                                          /* issue: could be optimise to exclude base 2 from this function */
		convertNumber(base);
		displayConvertedNumber();
	} else {                                                        /* handles positive integer input */
		convertNumber(base);
		displayConvertedNumber();
	}
	return 0;
}
