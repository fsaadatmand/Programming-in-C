/* 
 * File copy program using command-line arguments
 * Program to copy one file to another - version 2
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int  c;

	if (argc != 3) {
		fprintf(stderr, "Need two files names\n");
		return 1;
	}

	if ((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't read %s.\n", argv[1]);
		return 2;
	}

	if ((out = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr, "Can't write %s.\n", argv[2]);
		return 3;
	}

	while ((c = getc(in)) != EOF)
		putc(c, out);

	printf("File has been copied.\n");

	fclose(in);
	fclose(out);

	return 0;
}
