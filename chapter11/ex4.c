/*
 * 4. Using the result obtained in exercise 3, modify the rotate() function
 * from Program 11.4 so that it no longer makes any assumptions about the size
 * of an int.
 *
 * By Faisal Saadatmand 
 */

#include <stdio.h>

/* functions */
size_t int_size();
unsigned int rotate(unsigned int, int);

/* Function to determine the size of an integer storged on this machine */
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

/* Function to rotate an unsigned int left to right */
unsigned int rotate(unsigned int value, int n)
{
	unsigned int result, bits;
	const size_t size = int_size();

	/* scale down the shift count to a defined range */

	if (n > 0)
		n = n % size;
	else
		n = -(-n % size);

	if (n == 0)
		result = value;
	else if (n > 0) {            /* left rotate */
		bits = value >> (size - n);
		result = value << n | bits;
	} else {                     /* right rotate */
		n = -n;
		bits = value << (size - n);
		result = value >> n | bits;
	}
	return result;
}

int main(void) 
{
	unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;

	printf("%x\n", rotate(w1, 8));
	printf("%x\n", rotate(w1, -16));
	printf("%x\n", rotate(w2, 4));
	printf("%x\n", rotate(w2, -2));
	printf("%x\n", rotate(w1, 0));
	printf("%x\n", rotate(w1, 44));

	return 0;
}
