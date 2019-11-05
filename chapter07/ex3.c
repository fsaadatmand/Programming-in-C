/*
 * 3. Modify Program 7.8 so that the value of epsilon is passed as an argument
 * to the function. Try experimenting with different values of epsilon to see
 * the effect that it has on the value of the square root.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* functions */
float absoluteValue(float);
float squareRoot(float, const float);

/* Function to calculate the absolute value of a number */
float absoluteValue(float x)
{
	if (x < 0)
		x = -x;

	return x;
}

/* Function to compute the square root of a number */
float squareRoot(float x, const float epsilon)
{
	float guess = 1.0;

	while (absoluteValue(guess * guess - x) >= epsilon)
		guess = (x / guess + guess) / 2.0;

	return guess;
}

int main(void) 
{
	const float epsilon = .00001;

	printf("squareRoot(2.0) = %f\n", squareRoot(2.0, epsilon));
	printf("squareRoot(144.0) = %f\n", squareRoot(144.0, epsilon));
	printf("squareRoot(17.5) = %f\n", squareRoot(17.5, epsilon));

	return 0;
}
