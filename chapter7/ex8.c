/* Program to solve quadratic equations */

#include <stdio.h>

/* Function to calculate the absolute value of a number */
float absoluteValue(float x)
{
	if (x < 0)
		x = -x;

	return (x);
}

/* Function to compute the square root of a number */
double squareRoot(double x, const double epsilon)
{
	double guess         = 1.0;

	do {
		guess = (x / guess + guess) / 2.0;
	} while (absoluteValue((guess * guess) / x) >= epsilon); 

	return guess;
}


int main(void) 
{
	
	int       	a, b, c, x1, x2, discriminant, leftVar, rightVar;
	float       absoluteValue(float x);
	double      squareRoot(double x, const double epsilon);


	printf("Enter value for a: ");
	scanf("%i", &a);

	printf("Enter value for b: ");
	scanf("%i", &b);

	printf("Enter value for c: ");
	scanf("%i", &c);

	discriminant = (b * b) - (4 * a * c);
	
	if (a == 0)
		printf("division by zero\n");

	else if (discriminant < 0)
		printf("Values of x1 and x2 are imaginary.\n");

	else { 
		leftVar = -b / (2 * a);
		rightVar = squareRoot(discriminant, 1.00001) / (2 * a);

		x1 = leftVar + rightVar;
		x2 = leftVar - rightVar;

		printf("x1 = %i, x2 = %i\n", x1, x2);
	}	

	return 0;
}
