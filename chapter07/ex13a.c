/* 
 * 13. Modify the sort() function from Program 7.12 to take a third argument
 * indicating whether the array is to be sorted in ascending or descending
 * order. Then modify the sort() algorithm to correctly sort the array into the
 * indicated order.
 *
 * By Faisal Saadatmand
 */

/*
 * Note: This sort version is a simplified version of qsort (see
 * documentation). It uses pointers and function pointers, which will be
 * discussed in chapter 10. 
 *
 */

#include <stdio.h>
#include <stdbool.h>

/* functions */
void swap(int *, int *);
void sort(int *, int, int (*)(const int *, const int *));
int greater(const int *, const int *);
int less(const int *, const int *);

void swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/* sort: sort arry a, according to the predicate, i.e. comparator. */
void sort(int *a, int n, int (*comp)(const int *, const int *))
{
	int *p, *q, *end;

	/* default comparator: ascending order */
	if (!comp)
		comp = greater;

	end = a + n;
	for (p = a; p < end - 1; ++p)
		for (q = p + 1; q < end; ++q) 
			if (comp(p, q))
				swap(p, q);
}

int greater(const int *a, const int *b)
{
	return *a > *b;
}

int less(const int *a, const int *b)
{
	return *a < *b;
}

int main(void) 
{
	int i;
	int array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                    44, -3, -9, 12, 17, 22, 6, 11};

	printf("Before sorting:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	sort(array, 16, greater);
	printf("\n\nSorted in ascending order:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	sort(array, 16, less);
	printf("\n\nSorted in descending order:\n");
	for (i = 0; i < 16; ++i)
		printf(" %i", array[i]);

	printf("\n\n");

	return 0;
}
