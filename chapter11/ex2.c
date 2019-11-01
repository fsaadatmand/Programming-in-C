/* 
 * 2. Write a program that determines whether your particular computer performs
 * an arithmetic or a logical right shift.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 16

/* functions */
bool isArithmeticRS(void);
bool isLogicalRS(void);

/* check for 1 in the most significant bit */
bool isArithmeticRS(void) 
{
	signed int w = 0x0;

	w >>= 1;

	if (w >= 0x0)
		return	false; /* 0 was pushed into MSB */

	return true; /* 1 was pushed into MSB */
}

/* Alternatively you cancheck for 0 in the most significant bit */
bool isLogicalRS(void)
{
	signed int w = 0x0;

	w >>= 1;

	return (w < 0x0) ? false : true;
}

int main(void)
{
	printf("Your computer performs %s right shift\n",
			isArithmeticRS() ? "an arithmetic" : "a logical");

	return 0;
}
