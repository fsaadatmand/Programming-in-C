/* 
 * 8. To round off an integer i to the next largest even multiple of another
 * integer j, the following formula can be used:
 *
 *		Next_multiple = i + j - i % j
 *
 * For example, to round off 256 days to the next largest number of days evenly
 * divisible by a week, values of i = 256 and j = 7 can be substituted into the
 * preceding formula as follows:
 *
 * 		Next_multiple    = 256 + 7 - 256 % 7
 *                       = 256 + 7 - 4
 *                       = 259
 *
 * Faisal Saadatmand 
 */

#include <stdio.h>

int main(void)
{
	int Next_multiple, i, j;

	i = 256, j = 7;
	Next_multiple = i +j - i % j;
	printf("%d days next multiple evenly divisible by %d is %d\n",
			i, j, Next_multiple);

	return 0;
}
