/*
 * 5. A doubly linked list is a list in which each entry contains a pointer to
 * the preceding entry in the list as well as a pointer to the next entry in
 * the list. Define the appropriate structure definition for a doubly linked
 * list entry and then write a small program that implements a small doubly
 * linked list and prints out the elements of the list.
 *
 * By Faisal Saadatmand */

#include <stdio.h>

struct entry {
	int value;
	struct entry *previous;
	struct entry *next;
};

int main(void) 
{
	struct entry n1, n2, n3, n4, n5;
	struct entry *list_pointer = &n1;

	n1.value = 100;
	n1.previous = NULL;
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
	n5.next = NULL;

	int i = 1;
	while (list_pointer) {
		printf("n%i (%p)\n", i++, list_pointer);
		printf(" value: %i\n", list_pointer->value);
		printf(" next: %p\n", list_pointer->next);
		printf(" previous: %p\n", list_pointer->previous);
		list_pointer = list_pointer->next;
	}

	return 0;
}
