/* Program to extract and display each typed-in digit of the integer in English:
 * 932 = nine three two 
 * By Faisal Saadatmand
 * */

#include <stdio.h>
#include <ctype.h>

struct numInWords {
	char digit;
	char numbers[11];
};

int main(void)
{
	int i = 0, j; 
	char number[30];
	struct numInWords english_word[30] = 
	                       { { '0', "zero" }, { '1', "one"}, { '2', "two" },
	                         { '3', "three" }, { '4', "four" }, { '5', "five" },
	                         { '6', "six" }, { '7', "seven" }, { '8', "eight" },
	                         { '9', "nine" } };
//	char *words[] = { "zero", "one", "two", "three", "four",
	                          "five", "six", "seven", "eight", "nine" };
							  
	printf("Enter a number: ");
	scanf("%s", &number);

	while (number[i] != '\0') {
		if (isdigit(number[i])) {
			for (j = 0; j <= 10; ++j)
				if (number[i] == english_word[j].digit)
					printf("%s ", english_word[j].numbers);
		} else {
			printf("Invalid input\n");
			break;
		}
		++i;
	}

	printf("\n");

	return 0;
}

