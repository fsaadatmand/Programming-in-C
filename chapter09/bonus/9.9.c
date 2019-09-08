/* Program to use the dictionary lookup program using strcoll function */

#include <stdio.h>
#include <string.h>

struct entry {
	char word[15];
	char definition[50];
};

/* Function to look up a word inside a dictionary */
int lookup(const struct entry dictionary[], const char search[],
		   const int entries)
{
	int i;

	for (i = 0; i < entries; ++i)
		if (strcoll(search, dictionary[i].word) == 0)
			return i;

	return -1;
}

int main(void) 
{
	const struct entry dictionary[100] = 
		{ { "aardvark", "a burrowing African mammal"             },
		  { "abyss",    "a bottomless pit"                       },
		  { "acumen",   "mentally sharp; keen"                   },
		  { "addle",    "to become confused"                     },
		  { "aerie",    "a high nest"                            },
		  { "affix",    "to append; attach"                      },
		  { "agar",     "a jelly made from seaweed"              },
		  { "ahoy",     "a nautical call of greeting"            },
		  { "aigrette", "an ornamental cluster of feathers"      },
		  { "ajar",     "partially opened"                       } };

	char word[10];
	int  entries = 10;
	int  entry;
	
	int lookup(const struct entry dictionary[], const char search[],
			   const int entries);

	printf("Enter word: ");
	scanf("%14s", word);

	entry = lookup(dictionary, word, entries);

	if (entry != -1)
		printf("%s\n", dictionary[entry].definition);
	else
		printf("Sorry, the word %s is not in my dictionary.\n", word);

	return 0;
}
