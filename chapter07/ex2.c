/* 
 * 2. Modify Program 7.4 so the value of triangularNumber is returned by the
 * function. Then go back to Program 4.5 and change that program so that it
 * calls the new version of the calculateTriangularNumber() function.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* functions */
int calculateTriangularNumber(int);

int calculateTriangularNumber(int n)
{
	int i, triangularNumber;

	triangularNumber = 0;
	for (i = 0; i <= n; ++i)
		triangularNumber += i;

	return triangularNumber;
}

int main(void)
{
    int number, counter;

	for (counter = 0; counter <= 5; ++counter) {
		printf("What triangular number do you want? ");
		scanf("%i", &number);
		printf("Triangular number %i is %i\n", number,
				calculateTriangularNumber(number));
	}

    return 0;
}
