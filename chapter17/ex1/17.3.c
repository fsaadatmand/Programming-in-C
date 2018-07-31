/* Defining a DEBUG macro */

#include <stdio.h>
#include <stdlib.h>

// #define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)

int process(int i1, int i2) 
{
	int val;

	DEBUG("process(%i, %i)\n", i1, i2);
	
	val = i1 * i2;

	DEBUG("return %i\n", val);

	return val;
}

int main(int argc, char *argv[])
{
	int arg1 = 0, arg2 = 0;

	if (argc > 1)
		arg1 = atoi(argv[1]);
	
	if (argc == 3)
		arg2 = atoi(argv[2]);

	DEBUG ("process %i arguments\n", argc - 1);
	DEBUG ("arg1 = %i, arg2 = %i\n", arg1, arg2);

	printf("%d\n", process(arg1, arg2));

	return 0;
}
