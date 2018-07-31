/* Dictionary lookup program using binary search */

#include <stdio.h>
#include <string.h>

struct entry {
	char word[15];
	char definition[50];
};

/* Function to look up a word inside a dictionary */
int lookup(const struct entry dictionary[], const char search[], const int entries)
{
	int low = 0;
	int high = entries - 1;
	int mid, result;

	while (low <= high) {
		mid = (low + high) / 2;
		result = strcmp(dictionary[mid].word, search);

		if (result < 0)
			low = mid + 1;
		else if (result > 0)
			high = mid - 1;
		else 
			return mid;       /* found it */
	}

	return -1;                        /* not found */
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

	int  entries = 10;
	char word[15];
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
