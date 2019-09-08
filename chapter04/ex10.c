/* 
 * 10. What would happen if you typed a negative number into Program 4.8? Try
 * it and see.
 * Answer: if a negative number is entered, the output number will have a minus
 * sign at the begning of the reversed number and between each digit. For
 * example, if -1234 was entered, the output will be -4-3-2-1 
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void) {

	int number, right_digit;

	printf("Enter your number.\n");
	scanf("%i", &number);

	while (number !=0) {
		right_digit = number % 10;
		printf("%i", right_digit);
		number = number / 10;
	}

	printf("\n");

	return 0;
}
