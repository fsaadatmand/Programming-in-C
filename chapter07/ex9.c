/* 
 * 9. The least common multiple (lcm) of two positive integers u and v is the
 * smallest positive integer that is evenly divisible by both u and v. Thus,
 * the lcm of 15 and 10, written lcm (15, 10), is 30 because 30 is the smallest
 * integer divisible by both 15 and 10. Write a function lcm() function should
 * calculate the least common multiple by calling the gcd() function from
 * Program 7.6 in accordance with the following identity:
 *
 *		lcm (u, v) = uv / gcd (u, v)        u, v >= 0
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* functions */
int absoluteValue(int);
int gcd(int, int);
int lcm(int, int);

int absoluteValue(int x)
{
	if (x < 0)
		x = -x;

	return x;
}

/* gcd: find and return the greatest common divisor of two non-negative
 * integers vales. */
int gcd(int u, int v)
{
	int temp;

	while (v != 0) {
		temp = u % v;
		u = v;
		v = temp;
	}

	return u;
}

/* lcm: calculate and return the least common multiplier of two non-negative
 * integers */
int lcm(int u, int v)
{
	if (u == 0 && v == 0)
		return 0;

	/* ignore negative signs, if any */
	u = absoluteValue(u);
	v = absoluteValue(v);

	return (u * v) / gcd(u, v);
}

int main(void) 
{
	int u, v;

	printf("Enter two numbers to calculate the least common multiplier:\n");
	scanf("%i %i", &u, &v);
	printf("The LCM of %i and %i is %i\n", u, v, lcm(u, v));

	return 0;
}
