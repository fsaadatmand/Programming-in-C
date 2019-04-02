/*
 * 5. Identify the syntactic errors in the following program. Then type in and
 * run the corrected program to ensure you have correctly identified.
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void) 
{
	int sum;               /* INT should be lowercase */

	/* The comments' syntax was wrong */
	/* COMPUTE RESULT */
	sum = 25 + 37 - 19;    /* missing semicolon at the end */

	/* DISPLAY RESULTS  */
	printf("The answer is %i\n", sum);  /* Missing a comma before
										   the variable sum */
	return 0;
}
