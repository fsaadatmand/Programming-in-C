/* 
 * 4. If you take the value of N as computed in exercise 2, subtract 621,049
 * from it, and then take that result modulo 7, you get a number from 0 to 6
 * that represents the day of the week (Sunday through Saturday, respectively)
 * on which the particular day falls. For example, the value of N computed for
 * August 8, 2004, is 732,239 as derived previously.  732,239 − 621,049 gives
 * 111,190, and 111,190 % 7 gives 2, indicating that this date falls on a
 * Tuesday.  Use the functions developed in the previous exercise to develop a
 * program that displays the day of the week on which a particular date falls.
 * Make certain that the program displays the day of the week in English (such
 * as “Monday”).
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

struct Date {
	int  day;
	int  month;
	int  year;
};

struct WeekDays {
	char day[9];
};

/* functions */
int year(const int, const int);
int month(const int);
int days(const struct Date);

/* month: return the value of the year according to the Gregorian calendar */
int year(const int year, const int month)
{
	return (month <= 2) ? year - 1 : year;
}

/* month: returns the value of month according to the Gregorian calendar */
int month(const int month)
{
	return (month <= 2) ? month + 13 : month + 1;
}

/* days: calculate the elapsed number of days since Unix epoch */
int days(const struct Date x)
{
	return (1461 * year(x.year, x.month)) / 4
		   + (153 * month(x.month)) / 5 + x.day;
}

int main(void)
{
	int i;
	struct Date d;
	const struct WeekDays days_of_week[] = { {"Sunday"},
											 {"Monday"},
											 {"Tuesday"},
											 {"Wednesday"},
											 {"Thursday"},
											 {"Friday"}, 
											 {"Saturday"} };

	printf("Enter a date (dd mm yyyy): ");
	scanf("%d%d%d", &d.day, &d.month, &d.year);

	i = (days(d) - 621049) % 7;

	printf("%s\n", days_of_week[i].day);
	
	return 0;
}
