/*
 * 6. Write a program to evaluate the polynomial shown here:
 *        3x^3 - 5x^2 + 6, for x = 2.55.
 *    for x = 2.55.
 * by Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	float pol, x = 2.55;

	pol = (3 * x * x * x)  - (5 * x * x) + 6;
	printf("the result of the polynomial is %g\n", pol);

	return 0;
}
