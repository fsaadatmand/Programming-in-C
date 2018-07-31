/* function to report time */

#include <stdio.h>
#include <stdbool.h>

struct date {
	int month;
	int day;
	int year;
};

struct time {
	int hour;
	int minutes;
	int seconds;
};

struct dateAndTime {
	struct date sdate;
	struct time stime;
};

/* function to update the time by one second */
struct time timeUpdate(struct time now)
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
bool isLeapYear(struct date d)
{
	bool leapYearFlag;

	if ((d.year % 4 == 0 && d. year % 100 !=0) || d.year % 400 == 0)
			leapYearFlag = true;       /* it's a leap year */
	else
		leapYearFlag = false;          /* not a leap year */
	return leapYearFlag;
}

/* function to find the number of days in a month */
int numberOfDays(struct date d)
{
	int days;
	bool isLeapYear(struct date d);

	const int daysPerMonth[12] =
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(d) && d.month == 2)
		days = 29;
	else
		days = daysPerMonth[d.month -1];
	return days;
}

/* function to update the date by one day */
struct date dateUpdate(struct date today)
{
	struct date tomorrow;
	int numberOfDays(struct date d);

	if (today.day != numberOfDays (today))
		tomorrow = (struct date) {today.month, today.day + 1, today.year};
	else if (today.month == 12)                       /* end of year */
		tomorrow = (struct date) {1, 1, today.year + 1};
	else                                              /* end of month */
		tomorrow = (struct date) {today.month + 1, 1, today.year};
	return tomorrow;
}


struct dateAndTime clockKeeper(struct dateAndTime d)
{
	d.stime = timeUpdate(d.stime);	
	if (d.stime.hour == 0)                           /* change date on midnight */
		d.sdate = dateUpdate(d.sdate);
	return d;
}

int main(void)
{
	struct time           timeUpdate(struct time now);
    bool                  isLeapYear(struct date d);
    int                   numberOfDays(struct date d);
    struct date           dateUpdate(struct date today);
	struct dateAndTime    clockKeeper(struct dateAndTime d);
	struct dateAndTime    event = 
	                      { { 12, 31, 2018 }, { 23, 59, 59 } };
	event = clockKeeper(event);
	printf("%i/%i/%i, %.2i:%.2i:%.2i\n", event.sdate.day, event.sdate.month,
			event.sdate.year, event.stime.hour, event.stime.minutes, 
			event.stime.seconds);

	return 0;
}
