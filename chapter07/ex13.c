/* 
 * 13. Modify the sort() function from Program 7.12 to take a third argument
 * indicating whether the array is to be sorted in ascending or descending
 * order. Then modify the sort() algorithm to correctly sort the array into the
 * indicated order.
 *
 * By Faisal Saadatmand
 */

/*
 * Note: this exercise could be made more succinct and efficient by using
 * features that have not been discussed at this point in the book. See
 * ext13a.c for an implementation.
 */

#include <stdio.h>
#include <stdbool.h>

/* functions */
void sort(int [], int, bool);

void sort(int a[], int n, bool descending)
{
	int i, j, temp, cond;

	for (i = 0; i < n - 1; ++i) 
		for (j = i + 1; j < n; ++j) {
			cond = (descending) ? a[i] < a[j] : a[i] > a[j];
			if (cond) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
}

int main(void) 
{
	int i;
	int array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                     44, -3, -9, 12, 17, 22, 6, 11};


	printf("\nBefore sorting:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	sort(array, 16, 0);
	printf("\n\nSorted in ascending order:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	sort(array, 16, 1);
	printf("\n\nSorted in descending order:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	printf("\n\n");

	return 0;
}
