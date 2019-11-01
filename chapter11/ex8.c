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
 * about the particular size of an int (refer to exercise 3 in this chapter).
 *
 * By Faisal Saadatmand
 */

 // Note: field is the number of bits to be set in w.

#include <stdio.h>

/* functions */
size_t int_size();
void bitpat_set(unsigned int *, unsigned int, int, int);

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

/* Function to set a specified set of bits to a particular value */
void bitpat_set(unsigned int *w, unsigned int value,
				int starting_bit, int field)
{
	unsigned int mask;
	int pos;

	/* Position of the set of bits */  
	pos = int_size() - starting_bit - field;

	/* create a field mask and aligned it with position */
	mask = ~(~(~0x0 << field) << pos);

	/* Zero bits' field in w */
	*w &= mask;

	/* insert value of field into w */
	*w |= (value << pos);
}

int main(void) 
{
	unsigned int x = 0xffff;

	bitpat_set(&x, 0x55u, 16, 8);
	printf("%x\n", x);
	bitpat_set(&x, 0x0u, 28, 4);
	printf("%x\n", x);
	bitpat_set(&x, 0x1u, 31, 1);
	printf("%x\n", x);

	return 0;
}
