/*
 * 8. An equation of the form
 *
 *		ax2 + bx + c = 0
 *
 * is known as a quadratic equation. The values of a, b, and c in the preceding
 * example represent constant values. So
 *
 * 		4x2 - 17x - 15 = 0
 *
 * represents a quadratic equation where a = 4, b = −17, and c = −15.  The
 * values of x that satisfy a particular quadratic equation, known as the roots
 * of the equation, can be calculated by substituting the values of a, b, and c
 * into the following two formulas:
 *
 * 		SEE TEXTBOOK FOR FORMULA
 *
 * If the value of b2−4ac, called the discriminant, is less than zero, the
 * roots of the equation, x1 and x2, are imaginary numbers.
 *
 * Write a program to solve a quadratic equation. The program should allow the
 * user to enter the values for a, b, and c. If the discriminant is less than
 * zero, a message should be displayed that the roots are imaginary; otherwise,
 * the program should then proceed to calculate and display the two roots of
 * the equation. (Note: Be certain to make use of the squareRoot() function
 * that you developed in this chapter.)
 *
 * By Faisal Saadatmand
*/

#include <stdio.h>

/* functions */
double absoluteValue(double);
double squareRoot(double);

/* Function to calculate the absolute value of a number */
double absoluteValue(double x)
{
	if (x < 0)
		x = -x;

	return x;
}

/* Function to compute the square root of a number */
double squareRoot(double x)
{
	const double epsilon = 1.00001;
	double guess = 1.0;

	do {
		guess = (x / guess + guess) / 2.0;
	} while (absoluteValue((guess * guess) / x) >= epsilon); 
	return guess;
}

int main(void) 
{
	double a, b, c, x1, x2, discriminant;

	printf("Enter values for a, b and c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	if (a == 0) {
		printf("The value of (a) must be a nonzero constant\n");
		return -1;
	}

	discriminant = (b * b) - (4 * a * c);

	if (discriminant < 0)
		printf("The roots of the equation, x1 and x2, are imaginary.\n");
	else { 
		x1 = (-b + squareRoot(discriminant)) / (2 * a);
		x2 = (-b - squareRoot(discriminant)) / (2 * a);
		printf("x1 = %g, x2 = %g\n", x1, x2);
	}	
	return 0;
}
