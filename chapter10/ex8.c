/* 
 * 8. Write a function called sort3() to sort three integers into ascending
 * order. (This function is not to be implemented with arrays.)
 *
 * By Faisal Saadatmand 
 */

#include <stdio.h>

/* functions */
void swap(int *, int *);
void sort3(int *, int *, int *);

/* swap: swap the objects pointed to by p with the object pointed to by q. */
void swap(int *p, int *q)
{
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

/* sort3: sorts 3 integers in ascending order (uses bubble sort algorithm) */
void sort3(int *a, int *b, int *c)
{	
	if (*a > *b)
		swap(a, b);
	if (*a > *c)
		swap(a, c);
	if (*b > *c)
		swap(b, c);
}

int main(void) 
{
	int i1 = 110, i2 = 345, i3 = 81;

	printf("%i %i %i -> ", i1, i2, i3); 
	sort3(&i1, &i2, &i3);
	printf("%i %i %i\n", i1, i2, i3); 

	return 0;
}
