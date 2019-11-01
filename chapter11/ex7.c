/*
 * 7. Write a function called bitpat_get() to extract a specified set of bits.
 * Have it take three arguments: the first an unsigned int, the second an
 * integer starting bit number, and the third a bit count. Using the convention
 * that bit numbering starts at 0 with the leftmost bit, extract the specified
 * number of bits from the first argument and return the result. So the call
 *
 *		bitpat_get (x, 0, 3)
 *
 * extracts the three leftmost bits from x. The call
 *
 *		bitpat_get (x, 3, 5)
 *
 * extracts five bits starting with the fourth bit in from the left.
 *
 * By Faisal Saadatmand
*/

#include <stdio.h>

/* functions */
size_t int_size();
unsigned int bitpat_get(unsigned int, int, int);

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

/* Function to extract a specified set of bits */
unsigned int bitpat_get(unsigned int w, int position, int nBits)
{
	unsigned bit_position, bits;

	/* out of bounds check */
	if (position < 0 || position > (int) int_size() - nBits)
		return -1;

	bits = ~(~0 << nBits);
	bit_position  = int_size() - position - nBits;

	return  w >> bit_position & bits;
}

int main(void) 
{
	const unsigned int x = 0xe1f4;

	// bit 0 in int on this machine
	printf("%x\n", bitpat_get(x, 0, 3));

	// reverse 8-bit word 
	printf("%x", bitpat_get(x, 28, 4));
	printf("%x", bitpat_get(x, 24, 4));
	printf("%x", bitpat_get(x, 20, 4));
	printf("%x\n", bitpat_get(x, 16, 4));

	// outside of word boundaries
	printf("%x\n", bitpat_get(x, 32, 4));
	printf("%x\n", bitpat_get(x, -1, 4));

	return 0;
}
