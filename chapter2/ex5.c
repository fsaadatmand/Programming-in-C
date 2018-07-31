/* Identifying and correcting the syntactical erros in the give program */

#include <stdio.h>

int main(void) 
{
	/* INT should be lowercase */
	int sum;
	/* The comments' syntax was wrong */

	// COMPUTE RESULT
	sum = 25 + 37 - 19;    

	// DISPLAY RESULTS 
	/* Missing a comma before the variable sum */
	printf("The answer is %i\n", sum); 

	return 0;
}
