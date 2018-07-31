/* Illustrating pointers */

#include <stdio.h>

int main(void) 
{
	int count = 10, x;
	int *int_pointer;      /* declare a variable of type pointer to int "*" */

	int_pointer = &count;  /* create a  pointer with the address operator "&" */
	x = *int_pointer;      /* assign the value of the pointer to another
							  using the inderection operator "*" variable */

	printf("count = %i, x = %i\n", count, x);

	return 0;
}
