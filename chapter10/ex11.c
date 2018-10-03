/*
 * 11. Given the definition of a date structure as defined in this chapter,
 * write a function called dateUpdate() that takes a pointer to a date
 * structure as its argument and that updates the structure to the following
 * day (see Program 8.4).
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

struct date {
	int day;
	int month;
	int year;
};

/* Function to calculate tomorrow's date */
void dateUpdate(struct date *today)
{
	int numberOfDays(struct date d);
	struct date todayDate = *today;

	if (today->day != numberOfDays(todayDate)) {
		today->day += 1;
	} else if (today->month == 12) {                    /* end of year */
		today->day = 1;
		today->month = 1;
		today->year += 1;
	} else {                                            /* end of month */
		today->day = 1;
		today->month += 1;
	}
}

/* Function to find the number of days in a month */
int numberOfDays(struct date d)
{
	int days;
	bool isLeapYear(struct date d);
	const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30,
		                           31, 31, 30, 31, 30, 31 };

	if (isLeapYear(d) == true && d.month == 2)
		days = 29;
	else
		days = daysPerMonth[d.month - 1];

	return days;
}

/* Function to determine if it's a leap year */
bool isLeapYear(struct date d)
{
	bool leapYearFlag;

	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		leapYearFlag = true;    /* it's a leap year */
	else
		leapYearFlag = false;    /* Not a leap year */
	
	return leapYearFlag;
}

int main(void)
{
	struct date thisDay;

	void dateUpdate(struct date *today);
	bool isLeapYear(struct date d);

	printf("Enter today's date (dd mm yyyy): ");
	scanf("%i%i%i", &thisDay.day, &thisDay.month, &thisDay.year);

	dateUpdate(&thisDay);
		
	printf("Tomorrow date is %i/%i/%.2i.\n", thisDay.day, thisDay.month,
			thisDay.year % 100);

	return 0;
}
