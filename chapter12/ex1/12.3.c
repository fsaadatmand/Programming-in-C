/* 
 * Program to illustrate the use of the #include statement
 * Note: This program assumes that definitions are
 * set up in a file called metric.h
 */

#include <stdio.h>

#include "metric.h"

int main(void)
{
	float liters, gallons;

	printf("*** Liters to Gallons ***\n\n");
	printf("Enter the number of liters: ");
	scanf("%f", &liters);

	gallons = liters * QUARTS_PER_LITER / 4.0;
	printf("%g liters = %g gallons\n", liters, gallons);

	return 0;
}
