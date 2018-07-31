/* Function to extract a specified set of bits */

#include <stdio.h>

/* Function that returns the number of bits contained in an integer. */
int int_size(int w)
{
	int mask, nBits = 0, nibble = 4;
	
	mask = ~0;                     /* Integer full of 1's */
	if (w >= 0) {
		w = ~w;                    /* One's complement to invert the bits */
		while (w != mask) {
			w >>= 1;               /* Right shift until w equals mask */
			++nBits;
		}
		if (nBits % nibble !=0)    /* Ensure each nibble is 4 bits */
			nBits += nibble - nBits % nibble;
	} else if (w < 0) {            /* Negative integers */
		w |= mask;                 /* Set all bits to 1 */
		while (w != 0) {           /* Left shift until w equal zero */
			w <<= 1;          
			++nBits;
		}
	}

	return nBits;
}

/* Function to extract a specified set of bits */
unsigned int bitpat_get(unsigned int w, int position, int nBits)
{
	unsigned int bits;
	int mask = ~0;

	bits = w >> ((int_size(w) - position) - nBits) & ~(mask << nBits);

	return bits;
}

int main(void) 
{
	int int_size(int w);
	unsigned int bitpat_get(unsigned int w, int position, int nBits);

	unsigned int x;
	x = 0xe1f4;
	
	printf("%x\n", bitpat_get(x, 0, 3));
	printf("%x\n", bitpat_get(x, 3, 5));
	printf("%x\n", bitpat_get(x, 8, 4));

	return 0;
}
