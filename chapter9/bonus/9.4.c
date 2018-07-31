/* Testing strings for equality using strcoll function */

#include <stdio.h>
#include <string.h>

int main(void) 
{
	const char stra[] = "string compare test";
	const char strb[] = "string";

	printf("%i\n", strcoll(stra, strb));
	printf("%i\n", strcoll(stra, stra));
	printf("%i\n", strcoll(strb, "string"));

	return 0;
}
