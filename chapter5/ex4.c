/* A simple "printing" calculator program by Faisal Saadatmand */

#include <stdio.h>

int main(void)
{
	float number, accumulator;
	char operator;

	printf("Begin Calculations\n\n");
	scanf("%f %c", &number, &operator);

	while (operator != 'E') {
		if (operator == 'S')
			printf("= %f\n\n", accumulator = number);
		else if (operator == '+')
			printf("= %f\n\n", accumulator += number);
		else if (operator == '-')
			printf("= %f\n\n", accumulator -= number);
		else if(operator == '*')
			printf("= %f\n\n", accumulator *= number);
		else if (operator == '/') {
			if (number == 0)
				printf("Division by zero\n\n");
			else
				printf("= %f\n\n", accumulator /= number);
		} else
			printf("Uknown operator\n\n");

		scanf("%f %c", &number, &operator);
	}
	
	printf("= %f\n\n", accumulator);
	printf("End of Calculations\n\n");

	return 0;
}
