/*
 * 5. The criteria used for termination of the loop in the squareRoot()
 * function of Program 7.8 is not suitable for use when computing the square
 * root of very large or very small numbers. Rather than comparing the
 * difference between the value of x and the value of guess2, the program
 * should compare the ratio of the two values to 1. The closer this ratio gets
 * to 1, the more accurate the approximation of the square root.
 * Modify Program 7.8 so this new termination criteria is used.
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* Function to calculate the absolute value of a number */
float absoluteValue(float x)
{
	if (x < 0)
		x = -x;
	return (x);
}

/* Function to compute the square root of a number */

double squareRoot(float x, const float epsilon)
{
	float guess         = 1.0;

	do {
		guess = (x / guess + guess) / 2.0;
	} while (absoluteValue((guess * guess) / x) >= epsilon); 
	return guess;
}

int main(void) 
{
	printf("squareRoot(2.0) = %f\n", squareRoot(2.0, 1.00001));
	printf("squareRoot(144.0) = %f\n", squareRoot(144.0, 1.00001));
	printf("squareRoot(17.5) = %f\n", squareRoot(17.5, 1.00001));

	return 0;
}
