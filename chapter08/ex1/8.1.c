/* Illustrating a structure */

#include <stdio.h>

int main(void) 
{
	struct date {
		int day;
		int month;
		int year;
	};

	struct date today;

	today.day = 4;
	today.month = 6;
	today.year = 2018;

	printf("Today's date is %i/%i/%.2i.\n", today.day, today.month, today.year % 100);

	return 0;
}
