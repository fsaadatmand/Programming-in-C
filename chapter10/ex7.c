/* 
 * Sorting an array of integers into ascending order using pointers
 * by Faisal Saadatmand 
 */

#include <stdio.h>

void sort(int *array, int n)
{
	int temp;
	int * const arrayEnd = array + n;
	int *ptr;

	for ( ; array < arrayEnd; ++array)
		for (ptr = array + 1; ptr < arrayEnd; ++ptr)
			if (*array > *ptr) {
				temp = *array;
				*array = *ptr;
				*ptr = temp;
			}
}

int main (void) 
{
	int i;
	int array[16] = { 34, -5, 2, 0, 12, 100, 56, 22,
                    44, -3, -9, 11, 17, 29, 6, 18 };

	void sort(int *array, int n);

	printf("The array before the sort:\n");
	for (i = 0; i < 16; ++i)
		printf("%i ", array[i]);

	sort (array, 16);

	printf("\n\nThe array after the sort:\n");
	for (i = 0; i < 16; ++i)
		printf("%i ", array[i]);

	printf("\n");

	return 0;
}
