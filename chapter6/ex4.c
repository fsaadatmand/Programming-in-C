/*
 * Program to calculate the average of an arry of 10 floating-pont values
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void) {

	int   i;
	float number, sum = 0, average = 0, array[10];

	printf("Enter 10 numbers to calculate their average: \n");

	for (i = 0; i < 10; ++i) {
		scanf("%f", &number);
		array[i] = number;
		sum  += array[i];
	}

	printf("Average = %.2f\n", average = sum / 10);

	return 0;
}
