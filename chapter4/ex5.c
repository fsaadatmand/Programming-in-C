/* Reformat for readability */

#include <stdio.h>

int main(void)
{
	int n;           /* value of n */
	int two_n;       /* value of 2 to the power of n */

	printf("TABLE OF POWERS OF TWO\n\n");
	printf("n\t2 to the n\n" );
	printf("---\t-------------------\n");

	two_n = 1;

	for (n = 0; n <= 10; ++n) {
		printf( "%2i \t %i\n", n , two_n );
		two_n *=2;
	}

	return 0;
}


