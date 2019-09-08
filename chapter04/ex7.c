/* 
 * 7. A decimal point before the field width specification in a printf()
 * statement has a special purpose. Try to determine its purpose by typing in
 * and running the following program. Experiment by typing in different values
 * each time you are prompted.
 */

#include <stdio.h>

int main(void)
{
	int dollars, cents, count;

	for (count = 1; count <= 10; ++count) {
		printf("Enter dollars: ");
		scanf("%i", &dollars);

		printf("Enter cents: ");
		scanf("%i", &cents);

		printf("$%i.%.2i\n\n", dollars, cents);
	}

	return 0;
}
