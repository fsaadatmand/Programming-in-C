/*
 * 6. Develop insertEntry() and removeEntry() functions for a doubly linked
 * list that are similar in function to those developed in previous exercises
 * for a singly linked list. Why can your removeEntry() function now take as
 * its argument a direct pointer to the entry to be removed from the list?
 *
 * Answer: 
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

struct entry {
	int value;
	struct entry *previous;
	struct entry *next;
};

/* functions */
struct entry* insertEntry (struct entry *, struct entry *); 
struct entry* removeEntry(struct entry *);

/* insertEntry: insert element AFTER pos in the list */
struct entry* insertEntry (struct entry *element, struct entry *pos)
{	
	if (pos->next)
		pos->next->previous = element;

	element->next = pos->next;
	element->previous = pos;

	pos->next = element;

	return element;
}

/* removeEntry: remove the element in a list. Return a pointer to the entry
 * just after the one removed */
struct entry* removeEntry(struct entry *element)
{
	if (element->previous)
		(element->previous)->next = element->next;

	if (element->next)
		(element->next)->previous = element->previous;

	return element->next;
}

int main(void) 
{
	struct entry n1, n2, n3, n4, n5, n6;
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

	n6.value = 600;

	/* comment or uncommet to test */
	insertEntry(&n6, &n2);
//	list_pointer = removeEntry(&n2);
//	removeEntry(&n3);
//	removeEntry(&n5);

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
