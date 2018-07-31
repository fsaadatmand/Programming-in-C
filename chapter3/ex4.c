/*
 * A programm for temperature conversion.
 * The formula: C = (F - 32) / 1.8
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	float temp_f = 27, temp_c;

	temp_c = (temp_f - 32) / 1.8;
	
	printf("%g Fahrenheit equals %.2f Celsius\n", temp_f, temp_c);

	return 0;
}

	
