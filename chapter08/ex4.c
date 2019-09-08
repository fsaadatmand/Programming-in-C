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
 * By Faisal Saadatmand
 */

#include <stdio.h>

struct date {
	int  day;
	int  month;
	int  year;
};

struct day {
	int nChar;
	char day[9];
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

/* Function to calculate the value of N */
int valueOfN(struct date x)
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
	int              x, i;
	struct date      d;

	int year(struct date x), month(struct date x), valueOfN(struct date x);

	const struct day dayOfWeek[7] = { { 6, { 'S', 'u', 'n', 'd', 'a', 'y' } }, 
		                              { 5, { 'M', 'o', 'd', 'a', 'y' } },
		                              { 7, { 'T', 'u', 'e', 's', 'd', 'a', 'y' } },
								      { 9, { 'W', 'e', 'd', 'n', 'e', 's', 'd', 'a', 'y' } },
								      { 8, { 'T', 'h', 'u', 'r', 's', 'd', 'a', 'y' } },
								      { 6, { 'F', 'r', 'i', 'd', 'a', 'y' } },
								      { 8, { 'S', 'a', 't', 'u', 'r', 'd', 'a', 'y' } } };

	printf("Enter a date (dd mm yyyy): ");
	scanf("%i%i%i", &d.day, &d.month, &d.year);       /* issue: can't enter 0 
														 before day and month */

	x = (valueOfN(d) - 621049) % 7;    /* day of the week in number */
	
	for (i = 0 ; i <= dayOfWeek[x].nChar ; ++i)       /* loop for i is less of 
														 equal n character */
		printf("%c", dayOfWeek[x].day[i]);

	printf("\n");
	
	return 0;
}
