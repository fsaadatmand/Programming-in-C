/* 
 * 2. Write a program that determines whether your particular computer performs
 * an arithmetic or a logical right shift.
 *
 * Note: reverse the return values to create isLogicalRS() function instead.
 * You could also use retun values 0 and 1 if you did not want to use
 * stdbool.h. In which case, replace the if statement's condition with: 
 * if (isArithmetic == 1)
 *     ... 
 * else
 *     ...
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

bool isArithmeticRS(void) 
{
	signed int w = -1;

	w >>= 1;               /* Shift 1 bit to the right */
	/* Test the value of the most significant bit */
	if (w < 0)             /* 1 was pushed into MSB */
		return true;
	else if (w > 0)        /* 0 was pushed into MSB */
		return false;
}

int main(void)
{
	if (isArithmeticRS)
		printf("Your computer performs an arithmetic right shift\n");
	else
		printf("Yoour computer performs a logical right shift\n");
}
