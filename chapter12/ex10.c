/* 
 * 10. Consider the definition of the printint macro from this chapter:
 *
 * 		#define printint(n)  printf ("%i\n", x ## n)
 *
 * Could the following be used to display the values of the 100 variables
 * x1–x100? Why or why not?
 *
 * 		for (i = 1; i < 100; ++i) 
 * 			printx (i);
 *
 * Answer: No. Because the preprocessor will perform a literal text
 * substitution on the value of n for i. Thus, printf(i) will be evaluated as
 * printf("%i\n", xi). 
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

/* #define printint(n) printf("%i\n", x ## n)    Possibbly a typo. Author might 
												 have meant printx(n) */
#define printx(n)   printf("%i\n", x ## n)    

int main(void) 
{
	int x1 = 34, x2 = 39, x3 = 10, x4 = 52, x5 = 16;

	for (i = 1; i < 5; ++i)
		printx(i);   

	return 0;
}
