/*
 * 10. Write a function called dictionarySort() that sorts a dictionary, as
 * defined in Programs 9.9 and 9.10, into alphabetical order.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

struct entry {
	char word[15];
	char definition[50];
};

/* functions */
int compareStrings(char [], char []);
void switchStrings(char [], char []);
void dictionarySort(struct entry [], int);

/* Function to compare two character strings */
int compareStrings(char s1[], char s2[])
{
	int i = 0, answer;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		++i;

	if (s1[i] < s2[i])
		answer = -1; /* s1 < s2 */
	else if (s1[i] == s2[i])
		answer = 0; /* s1 == s2 */
	else
		answer = 1; /* s1 > s2 */

	return answer;
}

/* function that sorts a dictionary */
void dictionarySort(struct entry dictionary[], int entries)
{
	int i, j;
	struct entry temp;

	for (i = 0; i < entries; ++i)
		for (j = i + 1; j < entries; ++j)
			if (compareStrings(dictionary[i].word, dictionary[j].word) == 1) {
				temp = dictionary[i];
				dictionary[i] = dictionary[j];
				dictionary[j] = temp;
			}
}

int main(void) 
{
	struct entry dictionary[100] = 
		{ { "aardvark", "a burrowing African mammal"             },
		  { "affix",    "to append; attach"                      },
		  { "ahoy",     "a nautical call of greeting"            },
		  { "abyss",    "a bottomless pit"                       },
		  { "ajar",     "partially opened"                       },
		  { "acumen",   "mentally sharp; keen"                   },
		  { "aerie",    "a high nest"                            },
		  { "addle",    "to become confused"                     },
		  { "agar",     "a jelly made from seaweed"              },
		  { "aigrette", "an ornamental cluster of feathers"      } };

	int  i, entries = 10;

	dictionarySort(dictionary, entries);

	for (i = 0; i <= entries; ++i)
		printf("%s    \t%s\n", dictionary[i].word, dictionary[i].definition);
	
	return 0;
}
