/* 
 * Program that uses lcm function to find least common multiple between
 * two positive integers
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
	int lcm;

	if (u < 0 || v < 0) {
		return 1;
	} else { 
		lcm = (u * v) / gcd(u, v);
		return lcm;
	}
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
