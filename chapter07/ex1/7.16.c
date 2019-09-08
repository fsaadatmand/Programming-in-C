/* Illustrating static and automatic variables */

#include <stdio.h>

void auto_static(void)
{
	auto   int autoVar = 1;    /* "auto" type is unnecessary */
	static int staticVar = 1;

	printf("automatic = %i, static = %i\n", autoVar, staticVar);

	++autoVar;
	++staticVar;
}


int main(void) 
{
	int i;
	
	void auto_static(void);

	for (i = 0; i < 5; ++i)
		auto_static();

	return 0;
}
