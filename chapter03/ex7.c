/* 
 * 7. Write a program that evaluates the following expression and displays the
 * results (remember to use exponential format to display the result):
 *
 *     (3.31 x 10^-8 x  2.01 x 10^-7) / (7.16 x 10^-6 + 2.01 x 10^-8) 
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	double result;

	result = (3.31 * 10e-8 * 2.01 * 10e-7) / (7.16 * 10e-6 + 2.01 * 10e-8);
	printf("The result of the expression is %g\n", result);

	return 0;
}
