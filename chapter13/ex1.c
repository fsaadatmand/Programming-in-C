/*
 * 1. Define a type FunctionPtr() (using typedef) that represents a pointer to
 * a function that returns an int and that takes no arguments.  Refer to
 * Chapter 10, “Pointers,” for the details on how to declare a variable of this
 * type.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int foo(void)
{
	return 42;
}

typedef int (*FunctionPtr)(void);

int main(void) 
{
	FunctionPtr fp = foo;;
	printf("%i\n", fp());

	return 0;
}
