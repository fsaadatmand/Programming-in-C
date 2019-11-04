/*
 * 5. Write a function called clockKeeper() that takes as its argument a
 * dateAndTime structure as defined in this chapter. The function should call
 * the timeUpdate() function, and if the time reaches midnight, the function
 * should call the dateUpdate function to switch over to the next day. Have the
 * function return the updated dateAndTime structure.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

struct Date {
	int month;
	int day;
	int year;
};

struct Time {
	int hour;
	int minutes;
	int seconds;
};

struct DateAndTime {
	struct Date sdate;
	struct Time stime;
};

/* functions */
struct Time timeUpdate(struct Time);
bool isLeapYear(struct Date);
int numberOfDays(struct Date);
struct Date dateUpdate(struct Date);
struct DateAndTime clockKeeper(struct DateAndTime);

/* function to update the time by one second */
struct Time timeUpdate(struct Time now)
{
	++now.seconds;
	if (now.seconds == 60) {         /* next minute */
		now.seconds = 0;
		++now.minutes;
		if (now.minutes == 60) {     /* next hour */
			now.minutes = 0;
			++now.hour;
			if (now.hour == 24)      /* midnight */
				now.hour = 0;
		}
	}
	return now;
}

/* Function to determine if it's a leap year */
bool isLeapYear(struct Date d)
{
	bool leapYearFlag;

	if ((d.year % 4 == 0 && d. year % 100 !=0) || d.year % 400 == 0)
			leapYearFlag = true;       /* it's a leap year */
	else
		leapYearFlag = false;          /* not a leap year */
	return leapYearFlag;
}

/* function to find the number of days in a month */
int numberOfDays(struct Date d)
{
	int days;
	bool isLeapYear(struct Date d);

	const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31,
								  30, 31, 30, 31};

	if (isLeapYear(d) && d.month == 2)
		days = 29;
	else
		days = daysPerMonth[d.month -1];
	return days;
}

/* function to update the date by one day */
struct Date dateUpdate(struct Date today)
{
	struct Date tomorrow;
	int numberOfDays(struct Date d);

	if (today.day != numberOfDays(today))
		tomorrow = (struct Date) {today.month, today.day + 1, today.year};
	else if (today.month == 12)                       /* end of year */
		tomorrow = (struct Date) {1, 1, today.year + 1};
	else                                              /* end of month */
		tomorrow = (struct Date) {today.month + 1, 1, today.year};
	return tomorrow;
}


struct DateAndTime clockKeeper(struct DateAndTime d)
{
	d.stime = timeUpdate(d.stime);	
	if (d.stime.hour == 0) /* change date on midnight */
		d.sdate = dateUpdate(d.sdate);
	return d;
}

int main(void)
{
	struct DateAndTime event = { { 12, 31, 2018 }, { 23, 59, 59 } };

	event = clockKeeper(event);

	printf("%i/%i/%i %.2d:%.2d:%.2d\n", event.sdate.day, event.sdate.month,
			event.sdate.year, event.stime.hour, event.stime.minutes, 
			event.stime.seconds);

	return 0;
}
