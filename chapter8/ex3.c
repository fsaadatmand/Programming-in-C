/* Function to calculate elapsed time. By Faisal Saadatmand */

#include <stdio.h>

struct time {
	int hour;
	int minutes;
	int seconds;
};

struct time elapsed_time(struct time t1, struct time t2)
{
	int i, j, d;
	struct time timeDiff = {0, 0 ,0};
                                       /* convert times into seconds and take their difference */
	i = t1.hour * 60 * 60 + t1.minutes * 60 + t1.seconds;
	j = t2.hour * 60 * 60 + t2.minutes * 60 + t2.seconds;
	d = j - i;
	
	if (d < 0)                         /* if time crosses midnight substract 24 hrs */
		d = d + 86400;

	while (d != 0) {                   /* reformat the difference (hh mm ss) */
	++timeDiff.seconds;
		if (timeDiff.seconds == 60) {
			timeDiff.seconds = 0;
			++timeDiff.minutes;
			if (timeDiff.minutes == 60) { 
				timeDiff.minutes = 0;
				++timeDiff.hour;
			}
		}
		--d;
	}
	return timeDiff;
}

int main(void) 
{
	struct time elapsed_time(struct time t1, struct time t2);

	struct time time1 = { 3, 45, 15 };
	struct time time2 = { 9, 44, 3 };
	struct time elapsedTime;

	elapsedTime =  elapsed_time(time1, time2);

	printf("%i hours, %i minutes, %i seconds\n", elapsedTime.hour, elapsedTime.minutes,
			elapsedTime.seconds);

	return 0;
}
