/* Program to categorize a single character that is entered at the terminal */

#include <stdio.h>

int main(void)
{
	char c;

	printf("Enter a single character:\n");
	scanf("%c", &c);

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		printf("It's an alphabetic character.\n");
	else if (c >= '0' && c <= '9')
		printf("It's a digit.\n");
	else
		printf("It's a special character.\n");

	return 0;
}
