/*
 * 3. Given that the expression ~0 produces an integer that contains all 1s,
 * write a function called int_size() that returns the number of bits contained
 * in an int on your particular machine.
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>

size_t int_size()
{
	int x = ~0;
	size_t i = 0;

	while (x != 0x0) {
		x <<= 1;
		++i;
	}

	return i;
}

int main(void) 
{

	printf("int_size() -> %lu bits\n", int_size());
	/* for comparison */
	printf("sizeof() -> %lu bits\n", sizeof(int) * 8);

	return 0;
}
