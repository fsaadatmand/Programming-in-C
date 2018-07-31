/* Doubly linked list exercise. By Faisal Saadatmand */

#include <stdio.h>

struct entry {
	int          value;
	struct entry *previous;
	struct entry *next;
};

int main(void) 
{
	struct entry n0, n1, n2, n3, n4, n5;
	struct entry *list_pointer = &n1, *end_pointer = &n5;

	n1.value = 100;
	n1.previous = (struct entry *) 0;
	n1.next = &n2;

	n2.value = 200;
	n2.previous = &n1;
	n2.next = &n3;

	n3.value = 300;
	n3.previous = &n2;
	n3.next = &n4;

	n4.value = 400;
	n4.previous = &n3;
	n4.next = &n5;

	n5.value = 500;
	n5.previous = &n4;
	n5.next = (struct entry *) 0;

	printf("next values\n");

	while (list_pointer != (struct entry *) 0) {
		printf("%i\n", list_pointer->value);
		list_pointer = list_pointer->next;
	}
	
	printf("\nprevious values\n");

	while (end_pointer != (struct entry *) 0) {
		printf("%i\n", end_pointer->value);
		end_pointer = end_pointer->previous;
	}

	return 0;
}
