/* 
 * Program to calculate the number of elapsed days
 * between two days.
 * By Faisal Saadatmand
 */

#include <stdio.h>

struct date {
	int day;
	int month;
	int year;
};

int year(struct date x)
{
	int value;

	if (x.month <= 2)
		value = x.year - 1;
	else
		value = x.year;
	return value;
}

int month(struct date x)
{
	int value;
	 
	if (x.month <= 2)
		value = x.month + 13;
	else
		value = x.month + 1;
	return value;
}

/* Function to calculate the elapsed number of days */
int formula(struct date x)
{
	int N;

	N = (1461 * year(x)) / 4 + (153 * month(x)) / 5 + x.day;

	if (x.year > 1800 && x.year < 1900) {          /* Mar 1, 1800 to Feb 28, 1900 */
		if (x.month == 3 || x.month == 2)
			++N;
	} else if (x.year > 1700 && x.year < 1800) {   /* Mar 1, 1700 to Feb 28, 1800 */
		if (x.month == 3 || x.month == 2)
			N += 2;
	}
	return N;
}

int main(void)
{
	struct date start, end;

	int year(struct date x), month(struct date x), formula(struct date x);

	printf("Enter start date (dd mm yyyy): ");
	scanf("%i%i%i", &start.day, &start.month, &start.year);

	printf("Enter end date (dd mm yyyy): ");
	scanf("%i%i%i", &end.day, &end.month, &end.year);

	printf("Number of elapsed days is %i\n", formula(end) - formula(start));
	
	return 0;
}
