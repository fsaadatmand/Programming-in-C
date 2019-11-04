/* 
 * 3. Program 6.2 permits only 20 responses to be entered. Modify that program
 * so that any number of responses can be entered. So that the user does not
 * have to count the number of responses in the list, set up the program so
 * that the value 999 can be keyed in by the user to indicate that the last
 * response has been entered. (Hint: You can use the break statement here if
 * you want to exit your loop.)
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int i, ratingCounters[11], response;

	for (i = 0; i < 11; ++i)
		ratingCounters[i] = 0;

	printf("Enter your responses\n");

	for (i = 1; ; ++i) {
		scanf("%i", &response );
		if (response == 999)
			break;
		if (response < 1 || response > 10)
			printf("Invalid response: %i\n", response);
		else
			++ratingCounters[response];
	}

	printf("\n\nRating   Number of Responses\n");
	printf("-------  -----------------------\n");

	for (i = 0; i < 11; ++i)
		printf("%4i%14i\n", i, ratingCounters[i]);

	return 0;
}
