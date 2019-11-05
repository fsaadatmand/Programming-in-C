/* 
 * 14. Rewrite the functions developed in the last four exercises to use global
 * variables instead of arguments. For example, the preceding exercise should
 * now sort a globally defined array.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* globals */
int array[5] = {2, 5, 21, 18, 5};
const int size = 5;

/* functions */
int arraySum();

int arraySum()
{
	int i, sum = 0;

	for (i = 0; i < size; ++i)
		sum += array[i];

	return sum;
}

int main(void)
{
	printf("%i\n", arraySum());
	return 0;
}
