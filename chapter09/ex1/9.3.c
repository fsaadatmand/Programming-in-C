/* Concatenating character strings using null character */

#include <stdio.h>

int main(void)
{
	void  concat(char result[], const char str1[], const
				char str2[]);

	const char s1[] = { "Test " };
	const char s2[] = { "works." };
	char  s3[20];

	concat(s3, s1, s2);
	printf("%s\n", s3);

	return 0;
}

/* Function to concatenate two character strings */
void concat(char result[], const char str1[], const char str2[])
{
	int i, j;

	/* copy string to result */
	for (i = 0; str1[i] != '\0'; ++i)
		result[i] = str1[i];

	/*copy str2 to result */
	for (j = 0; str2[j] != '\0'; ++j)
		result[i + j] = str2[j];

	/* Terminate the concatenated string with a null character */

	result[i + j] = '\0';
}
