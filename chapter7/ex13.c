/* 
 * Sorting an array of integers into ascending order (Program 7.12)
 * modified to sort by ascending or descending order
 * depending on the value of the argument s in function sort
 * By Faisal Saadatmand
 */

#include <stdio.h>

void sort(int a[], int n, char s)
{
	int i, j, temp;

	if (s == 'a') 
		for (i = 0; i < n - 1; ++i) 
			for (j = i + 1; j < n; ++j)
				if (a[i] > a[j]) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
	else if (s == 'd')
		for (i = 0; i < n - 1; ++i)
			for (j = i + 1; j < n; ++j)
				if (a[i] < a[j]) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
	else
		printf("\n\n %c is an invalid sort criteria\n", s);
}

int main(void) 
{
	int i;
	int array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                    44, -3, -9, 12, 17, 22, 6, 11};

	void sort(int a[], int n, char s);

	printf("The array before the sort:\n");
	for (i = 0; i < 16; ++i)
		printf("%i ", array[i]);

	sort(array, 16, 'a');

	printf("\n\nThe array after the sort in ascending order:\n");
	for (i = 0; i < 16; ++i)
		printf("%i ", array[i]);

	sort(array, 16, 'd');

	printf("\n\nThe array after the sort in descending order:\n");
	for (i = 0; i < 16; ++i)
		printf("%i ", array[i]);

	printf("\n");

	return 0;
}
