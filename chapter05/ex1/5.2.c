/* 
 * Program to calculate the average of a set of grades and count 
 * the number of failing test grades 
 *
 * The if Statement:
 * if ( expression )
 * 		program statment
 */

#include <stdio.h>

int main(void)
{
	int   numberOfGrades, i, grade;
	int   gradeTotal = 0;
	int   failureCount = 0;
	float average;


	printf("How many grades will you be entering? ");
	scanf("%i", &numberOfGrades);

	for (i = 1; i <= numberOfGrades; ++i) {
		printf("Enter grade #%i: ", i);
		scanf("%i", &grade);
		gradeTotal = gradeTotal + grade;

		if (grade < 65)
			++failureCount;
	}

	average = (float) gradeTotal / numberOfGrades;

	printf("\nGrade average = %.2f\n", average);
	printf("Number of failures = %i\n", failureCount);

	return 0;
}
