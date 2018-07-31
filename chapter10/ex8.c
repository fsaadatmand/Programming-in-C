/* 
 * Function to sort 3 integers into ascending order
 * By Faisal Saadatmand 
 */

#include <stdio.h>

void sort3(int *a, int *b, int *c)
{	
	int temp;

	if (*a > *b) {
		temp = *b;
		*b = *a;
		*a = temp;
	}
	if (*a > *c) {
		temp = *c;
		*c = *a;
		*a = temp;
	}
	if (*b > *c) {
		temp = *c;
		*c = *b;
		*b = temp;
	}
}

int main(void) 
{
	void sort3(int *a, int *b, int *c);

	int i1 = 110, i2 = 345, i3 = 81;

	sort3(&i1, &i2, &i3);
	printf("%i %i %i\n", i1, i2, i3); 

	return 0;
}
