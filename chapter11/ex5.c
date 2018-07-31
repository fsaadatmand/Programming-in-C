/* 
 * bit_test and bit_set funtions. 
 * Note: bit 0 is the most significant bit in the integer to be tested.
 * By Faisal Saadatmand 
 */

#include <stdio.h>

/* Function that counts the number of bits contained in a given integer */
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

/* Function to check the On/Off status of a given bit inside an integer */
int bit_test(unsigned int w, int n)
{
	int msb, bit; 

	msb = int_size(w) - 1;      /* Location of most significant bit in w,
								   i.e. bit 0 */

	if (n < 0 | n > msb)        /* Check if n is inside the word (w) */
		return -1;

	bit = msb - n;              /* Location of the bit to be tested */
	w = w >> bit & 0x1;         /* Extract the bit */

	if (w == 0x1)               /* Test the status of the bit */
		return 1;               /* Bit is ON */
	else
		return 0;               /* Bit is OFF */
}

/* Function to set the status of a bit to On inside an integer */
unsigned int bit_set(unsigned int w, int n)
{
	int msb, bit; 

	msb = int_size(w) - 1;     /* Location of most significant bit in w,
	                              i.e. bit 0 */
	bit = msb - n;             /* Location of the bit to change */

	w |=  0x1 << bit;          /* Insert 1 into w at the location of var bit */

	return w;
}

int main(void) 
{
	int int_size(int w);
	int bit_test(unsigned int w, int n);
	unsigned int bit_set(unsigned int w, int n);

	unsigned int w = 0xff0u;
	int n = 8, result;         /* n is the value of the bit to be tested or
								  change */
	
	result = bit_test(w, n);

	printf("w = %x\n", w);

	if (result == 1)           /* Test the status of the n bit */
		printf("bit %i is ON\n", n);
	else if (result == 0) {
		printf("bit %i is OFF\n", n);
		printf("Turning bit %i ON will make w = %x\n", n, bit_set(w, n));
	} else
		printf("Bit is out of word\n");

	return 0;
}
