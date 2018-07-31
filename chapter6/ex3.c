/* 
 * Demonstrating an array of counters. Modify so that any number of responses
 * can be entered.
 */

#include <stdio.h>

int main(void)
{
	int ratingCounters[11], i, response;

	for (i =1; i <= 10; ++i)
		ratingCounters[i] = 0;

	printf("Enter your responses\n");

	for (i = 1; ; ++i) {
		scanf("%i", &response );
		if (response == 999)
			break;
		else if (response < 1 || response > 10)
			printf("Invalid response: %i\n", response);
		else
			++ratingCounters[response];
		}

		printf("\n\nRating   Number of Responses\n");
		printf("-------  -----------------------\n");
		
		for (i = 1; i <= 10; ++i)
			printf("%4i%14i\n", i, ratingCounters[i]);

	return 0;
}
