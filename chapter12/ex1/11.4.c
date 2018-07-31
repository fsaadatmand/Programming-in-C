/* Illustrate the use of #define for program portability */

#include <stdio.h>

#define KIntSize 32     /* *** machine dependent !!! *** */

/*Function to rotated an unsigned int left or right */
unsigned int rotate(unsigned int value, int n)
{
	unsigned int result, bits;

	/* scale down the shift count to a defined range */

	if (n > 0)
		n = n % KIntSize;
	else
		n = -(-n % KIntSize);

	if (n == 0)
		result = value;
	else if (n > 0) {     /* left rotate */
		bits = value >> (KIntSize - n);
		result = value << n | bits;
	} else {             /* right rotate */
		n = -n;
		bits = value << (KIntSize - n);
		result = value >> n | bits;
	}

	return result;
}

int main(void) 
{
	printf("%x\n", rotate(0x55ff, -4 ));

	return 0;
}
