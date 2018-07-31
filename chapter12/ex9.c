/*
 * Macro that computes the absolute value of its argument
 * Test: ABSOLUTE_VALUE(x + delta), where delta is the discriminant of the
 * quadratic equation. See exercise 8 from chapter 7.
 * By Faisal Saadatmand
 */

#include <stdio.h>

#define IS_NEGATIVE(x) ((x) < 0)
#define ABSOLUTE_VALUE(x) ((x) * -1)
#define SQUARE(x) ((x) * (x))
#define DELTA(a,b,c) ((SQUARE(b)) + (4 * (a) * (c)))

int main(void) 
{
	int value, x = -100, delta;

	delta = DELTA(4, -17, -15);

	if (IS_NEGATIVE(x + delta))
		value = ABSOLUTE_VALUE(x + delta);
	else
		value = x + delta;

	printf("The absolute value of x + delta (%i + %i) is %i\n", x, delta, value);

	return 0;
}
