/* 
 * 8. Write a function called bitpat_set() to set a specified set of bits to a
 * particular value. The function should take four arguments: a pointer to an
 * unsigned int in which the specified bits are to be set; another unsigned int
 * containing the value to which the specified bits are to be set, right
 * adjusted in the unsigned int; a third int that specifies the starting bit
 * number (with the leftmost bit numbered 0); and a fourth int specifying the
 * size of the field. So the call
 *
 * 		bitpat_set (&x, 0, 2, 5);
 *
 * has the effect of setting the five bits contained in x, beginning with the
 * third bit from the left (bit number 2), to 0. Similarly, the call
 *
 * 		bitpat_set (&x, 0x55u, 0, 8);
 *
 * sets the eight leftmost bits of x to hexadecimal 55. Make no assumptions
 * about the particular size of an int (refer to exercise 3 in this chapter(.
 *
 * Note: field is the size of the field of bits to be set in w.
 *
 * By Faisal Saadatmand
 */

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

/* Function to set a specified set of bits to a particular value */
void bitpat_set(unsigned int *w, unsigned int value, int starting_bit,
		int field)
{
	unsigned int x;
	int mask, size, position;

	x = *w;                                          /* Use local variable to 
														pass it to int_size() */
	mask = ~0;
	size = int_size(x);
	position = size - starting_bit - field;          /* Position of the set of
														bits */  

	x &= ~(~(mask << field) << position);            /* Zero bits' field in x */
	value = (value & ~(mask << field)) << position;  /* align value and field */
	x |= value;                                      /* insert value into x */
	*w = x;                                          /* Set value of &w */
}

int main(void) 
{
	void bitpat_set(unsigned int *w, unsigned int value, int starting_bit,
			int field);
	int int_size(int w);

	unsigned int x = 0xffff;

	bitpat_set(&x, 0x55u, 0, 8);
	printf("%x\n", x);

	return 0;
}
