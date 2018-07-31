/* Program to illustrate structure pointers */

#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

int main(void) 
{
	struct date today, *datePtr;

	datePtr = &today;

	datePtr->month = 9;
	datePtr->day = 25;
	datePtr->year = 2015;

	printf("Today's date is %i/%i/%.2i.\n",
			datePtr->month, datePtr->day, datePtr->year % 100);

	return 0;
}
