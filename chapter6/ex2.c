/* 
 * Working with an Array example. Modify program so elements of values array is
 * intitialised to 0. 
 */

#include <stdio.h>

int main(void)
{
	int values[10];
	int index;

	for (index = 0; index < 10; ++index) {
		values[index] = 0;
		printf("values[%i] = %i\n", index, values[index]);
	}

	values[0]  = 197;
	values[2]  = -100;
	values[5]  = 350;
	values[3]  = values[0] + values[5];
	values [9] = 
	values[5] / 10;
	--values[2];

	for (index = 0; index < 10; ++index)
		printf("values[%i] = %i\n", index, values[index]);

	return 0;
}
