/*
 * Function to convert all lowercase character in a string to uppercase 
 * by Faisal Saadatmand
 * */

#include <stdio.h>

void uppercase(char string[])
{
	int i = 0;

	while (string[i] != '\0')
		if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] = string[i] - 97 + 65;
			++i;
		} else
			++i;
}

int main(void) 
{
	void uppercase(char string[]);	

	char str[81] = "abcdfghijklmnopqrstuvwxyz";

	uppercase(str);

	printf("%s\n", str);

	return 0;
}
