/*
 * 5. The following perfectly valid C program was written without much
 * attention paid to its format. As you will observe, the program is not very
 * readable. (And believe it or not, it is even possible to make this program
 * significantly more unreadable!) Using the programs presented in this chapter
 * as examples, reformat the program so that it is more readable. Then type the
 * program into the computer and run it.
 *
 *	#include <stdio.h>
 * 	int main(void){
 * 	nt n,two_to_the_n;
 * 	printf("TABLE OF POWERS OF TWO\n\n");
 * 	printf(" n     2 to the n\n");
 * 	printf("---    ---------------\n");
 * 	two_to_the_n=1;
 * 	for(n=0;n<=10;++n){
 * 	printf("%2i        %i\n",n,two_to_the_n); two_to_the_n*=2;}
 * 	return 0;}
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int n;

	printf("TABLE OF POWERS OF TWO\n\n");
	printf("n\tn^2\n" );
	printf("---\t-------------------\n");

	for (n = 1; n <= 10; ++n) {
		printf("%2i \t %i\n", n , n * n);
	}
	return 0;
}
