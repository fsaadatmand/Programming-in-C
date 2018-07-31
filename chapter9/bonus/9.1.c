/* Using string functions: strcat */

#include <stdio.h>
#include <string.h>

int main(void) 
{
	char s1[20] = { 'T', 'e', 's', 't', ' ' };
	char s2[7] = { 'w', 'o', 'r', 'k', 's', '.' };

	printf("%s\n", strcat(s1, s2));

	return 0;
}
