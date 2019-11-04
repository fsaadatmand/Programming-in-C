/*
 * 3. Write a function elapsed_time that takes as its arguments two time
 * structures and returns a time structure that represents the elapsed time (in
 * hours, minutes, and seconds) between the two times.  So the call
 *
 *		elapsed_time (time1, time2)
 *
 * where time1 represents 3:45:15 and time2 represents 9:44:03, should return a
 * time structure that represents 5 hours, 58 minutes, and 48 seconds. Be
 * careful with times that cross midnight.  Function to calculate elapsed time.
 *
 * By Faisal Saadatmand
 * */

#include <stdio.h>

struct Time {
	int hours;
	int minutes;
	int seconds;
};

struct Time elapsed_time(struct Time, struct Time);

struct Time elapsed_time(struct Time t1, struct Time t2)
{
	struct Time td; // time difference

	td.seconds = t2.seconds - t1.seconds;
	td.minutes = t2.minutes - t1.minutes;
	td.hours = t2.hours - t1.hours;

	if (td.seconds < 0) {
		td.seconds += 60;
		--td.minutes;
	}

	if (td.minutes < 0) {
		td.minutes += 60;
		--td.hours;
	}

	/* time crosses midnight */
	if (td.hours < 0)
		td.hours += 24;

	return td;
}

int main(void) 
{
	struct Time time_1 = { 3, 45, 15 };
	struct Time time_2 = { 9, 44, 3 };
	struct Time time_d;

	time_d =  elapsed_time(time_1, time_2);

	printf("%i hours, %i minutes, %i seconds\n",
			time_d.hours, time_d.minutes, time_d.seconds);

	return 0;
}
