/*
 * 3. Given that the expression ~0 produces an integer that contains all 1s,
 * write a function called int_size() that returns the number of bits contained
 * in an int on your particular machine.
 *
 * Notes: negative integers represented in two's complement take up the entire
 * int size set by the compiler. On this system it is 32 bits or 4 Bytes.
 * Moreover, this method works for decimal and hexadecimal integers only. For
 * octal or other base integers change the nibble size appropriately.
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>

int int_size(int w)
{
	int mask, nBits = 0, nibbleSize = 4;
	
	mask = ~0;                     /* Integer full of 1's */
	if (w >= 0) {
		w = ~w;                    /* One's complement to invert the bits */
		while (w != mask) {        /* Check if number is positive */
			w >>= 1;               /* Right shift until w equals mask */
			++nBits;
		}

		if (nBits % nibbleSize !=0)    /* Ensure each nibble is 4 bits */
			nBits += nibbleSize - nBits % nibbleSize;

	} else if (w < 0) {            /* Negative integers */
			w |= mask;             /* Fill in all the bits, before counting */
		while (w != 0) {           /* Left shift until w equal zero */
			w <<= 1;          
			++nBits;
		}
	}

	return nBits;
}

int main(void) 
{
	int int_size(int w);

	long long signed int i = 1;

	printf("The size of the integer is %i bits\n", int_size(i));
	printf("sizeof() function result is %lu bytes\n", sizeof(i));

	return 0;
}
