/*
 * 8. An equation of the form
 *		ax2 + bx + c = 0
 * is known as a quadratic equation. The values of a, b, and c in the preceding
 * example represent constant values. So
 * 		4x2 - 17x - 15 = 0
 *
 * represents a quadratic equation where a = 4, b = −17, and c = −15.  The
 * values of x that satisfy a particular quadratic equation, known as the roots
 * of the equation, can be calculated by substituting the values of a, b, and c
 * into the following two formulas:
 * 		SEE TEXTBOOK
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
