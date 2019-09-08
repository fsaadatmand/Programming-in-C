/* 
 * 9. The least common multiple (lcm) of two positive integers u and v is the
 * smallest positive integer that is evenly divisible by both u and v. Thus,
 * the lcm of 15 and 10, written lcm (15, 10), is 30 because 30 is the smallest
 * integer divisible by both 15 and 10. Write a function lcm() function should
 * calculate the least common multiple by calling the gcd() function from
 * Program 7.6 in accordance with the following identity:
 *		lcm (u, v) = uv / gcd (u, v)        u, v >= 0
 * By Faisal Saadatmand
 */

#include <stdio.h>

int gcd(int u, int v)
{
	int temp;

	while (v !=0) {
		temp = u % v;
		u = v;
		v = temp;
	}
	return u;
}

int lcm(int u, int v)
{
	if (u < 0 || v < 0)
		return 1;
	else
		return (u * v) / gcd(u, v);
}

int main(void) 
{
	int u, v;

	int gcd(int u, int v);
	int lcm(int u, int v);

	printf("Enter value for u: ");
	scanf("%i", &u);

	printf("Enter value for v: ");
	scanf("%i", &v);

	if (lcm(u, v) == 1)
		printf("The value of u and v must be a positive integers\n");
	else
		printf("The lcm of %i and %i is %i\n", u, v, lcm(u, v));

	return 0;
}
