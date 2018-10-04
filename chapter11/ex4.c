/*
 * 4. Using the result obtained in exercise 3, modify the rotate() function
 * from Program 11.4 so that it no longer makes any assumptions about the size
 * of an int.
 * By Faisal Saadatmand 
 */

#include <stdio.h>

/* Function to determine the size of an integer storged on this machine */
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

/* Function to rotate an unsigned int left to right */
unsigned int rotate(unsigned int value, int n)
{
	int int_size(int w);

	unsigned int result, bits;
	int size;

	size = int_size(value);
	
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
	unsigned int rotate(unsigned int value, int n);

	unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;

	printf("%x\n", rotate(w1, 8));
	printf("%x\n", rotate(w1, -16));
	printf("%x\n", rotate(w2, 4));
	printf("%x\n", rotate(w2, -2));
	printf("%x\n", rotate(w1, 0));
	printf("%x\n", rotate(w1, 44));

	return 0;
}
