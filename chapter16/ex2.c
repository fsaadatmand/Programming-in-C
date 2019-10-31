/* 
 * 2. Finish the program that takes a word as a command-line argument and looks
 * up the word to see whether it is in the array of terms and definitions,
 * providing the definition if it is found, or informs the user that the term
 * is not in the program’s glossary if it isn’t found.
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

struct entry {
	char word[MAXLEN];
	char definition[MAXLEN];
};

int lookup(const struct entry [], const char [], const int);

int lookup(const struct entry dictionary[], const char search[],
		const int entries)
{
	int i;

	for (i = 0; i < entries; ++i)
		if (!strcmp(search, dictionary[i].word))
			return i;

	return -1;
}

int main(int argc, char *argv[]) 
{
	const struct entry dictionary[] =
	  { { "aardvark", "a burrowing African mammal"        },
		{ "abyss",    "a bottomless pit"                  },
		{ "acumen",   "mentally sharp; keen"              },
		{ "addle",    "to become confused"                },
		{ "aerie",    "a high nest"                       },
		{ "agar",     "a jelly made from seaweed"         },
		{ "ahoy",     "a nautical call of greeting"       },
		{ "aigrette", "an ornamental cluster of feathers" },
		{ "ajar",     "partially opened"                  } };

	int entries = sizeof(dictionary) / sizeof(dictionary[0]);
	int entryNumber;

	if (argc != 2) {
		fprintf(stderr, "No word typed on the command line.\n");
		return EXIT_FAILURE;
	}

	entryNumber = lookup(dictionary, argv[1], entries);

	if (entryNumber != -1)
		printf("%s\n", dictionary[entryNumber].definition);
	else
		printf("Sorry, %s is not in my dictionary.\n", argv[1]);

	return EXIT_SUCCESS;
}
