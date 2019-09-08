/* 
 * 2. In certain applications, particularly in the financial area, it is often
 * necessary to calculate the number of elapsed days between two dates.  For
 * example, the number of days between July 2, 2015, and July 16, 2015, is
 * obviously 14. But how many days are there between August 8, 2014, and
 * February 22, 2015? This calculation requires a bit more thought.  Luckily, a
 * formula can be used to calculate the number of days between two dates. This
 * is affected by computing the value of N for each of the two dates and then
 * taking the difference, where N is calculated as follows:
 *
 *		N = 1461 x f(year, month) / 4 + 153 x g(month) / 5  + day
 *	where:
 *		f(year, month)    =    year - 1          if  month <= 2
 *                             year              otherwise
 *
 *		g(month)  =       month + 13        if month <= 2
 *		                  month + 1         otherwise
 *
 * As an example of applying the formula, to calculate the number of days
 * between August 8, 2004, and February 22, 2005, you can calculate the values
 * of N1 and N2 by substituting the appropriate value into the preceding
 * formula as shown:
 * 		N1    = 1461 x f(2004, 8) / 4  +  153 x g(8) / 5  +  3
 *            = (1461 x 2004) / 4  +  (153 x 9) / 5  +  3
 *            = 2,927,844 / 4  +  1,377 / 5  +  3
 *            = 731,961 + 275 + 3 
 *            = 732,239
 *
 * 		N2    = 1461 x f(2005, 2) / 4  +  153 x g(2) / 5  +  21
 *            = (1461 x 2004) / 4  +  (153 x 15) / 5  +  21
 *            = 2,927,844 / 4  +  2295 / 5  +  21
 *            = 731,961 + 459 + 21
 *
 * So the number of days between the two dates is shown to be 202. The
 * preceding formula is applicable for any dates after March 1, 1900 (1 must be
 * added to N for dates from March 1, 1800, to February 28, 1900, and 2 must be
 * added for dates between March 1, 1700, and February 28, 1800).  Write a
 * program that permits the user to type in two dates and then calculates the
 * number of elapsed days between the two dates. Try to structure the program
 * logically into separate functions. For example, you should have a function
 * that accepts as an argument a date structure and returns the value of N
 * computed as shown previously.  This function can then be called twice, once
 * for each date, and the difference taken to determine the number of elapsed
 * days.
 *
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
