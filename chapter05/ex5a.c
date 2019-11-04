/* 
 * 5. You developed Program 4.9 to reverse the digits of an integer typed in
 * from the terminal. However, this program does not function well if you type
 * in a negative number. Find out what happens in such a case and then modify
 * the program so that negative numbers are correctly handled. For example, if
 * the number −8645 is typed in, the output of the program should be 5468−.
 *
 * This version uses a for loop instead of the do while loop.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>


int main()
{
	int number;
	bool negative = false;
	
	printf("Enter your number:\n");
	scanf("%i", &number);

	if (number < 0) {
		number = -number;
		negative = true;
	}

	for ( ; number > 0; number /= 10)
		printf("%i", number % 10);

	if (negative)
		printf("-");

	printf("\n");

	return 0;
}
