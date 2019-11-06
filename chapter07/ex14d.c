/* 
 * 14. Rewrite the functions developed in the last four exercises to use global
 * variables instead of arguments. For example, the preceding exercise should
 * now sort a globally defined array.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>
	
/* globals */
bool gSortOrder;

/* functions */
void sort(int [], int);

void sort(int a[], int n)
{
	int i, j, temp, cond;

	for (i = 0; i < n - 1; ++i) 
		for (j = i + 1; j < n; ++j) {
			cond = (gSortOrder) ? a[i] < a[j] : a[i] > a[j];
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
	int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
                  44, -3, -9, 12, 17, 22, 6, 11 };

	printf("\nBefore sorting:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	gSortOrder = false; /* ascending order */
	printf("\n\nSorted in ascending order:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	gSortOrder = true; /* descending order */
	sort(array, 16);
	printf("\n\nSorted in descending order:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	printf("\n\n");

	return 0;
}
