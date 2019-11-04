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

struct entryD {
	int value;
	struct entryD *previous;
	struct entryD *next;
};

/* functions */
struct entryD* insertEntry (struct entryD *, struct entryD *); 
struct entryD* removeEntry(struct entryD *);
void print_list(struct entryD *);

/* insertEntry: insert element AFTER pos in the list */
struct entryD* insertEntry (struct entryD *element, struct entryD *pos)
{	
	if (pos->next)
		pos->next->previous = element;

	element->next = pos->next;
	element->previous = pos;

	pos->next = element;

	return element;
}

/* removeEntry: remove the element in a list. Return a pointer to the entryD
 * just after the one removed */
struct entryD* removeEntry(struct entryD *element)
{
	if (element->previous)
		(element->previous)->next = element->next;

	if (element->next)
		(element->next)->previous = element->previous;

	return element->next;
}

void print_dlist(struct entryD *p)
{
	int i;

	for (i = 1; p; ++i) {
		printf("n%i (%p)\n", i, (void *) p);
		printf(" value: %i\n", p->value);
		printf(" next: %p\n", (void *) p->next);
		printf(" previous: %p\n", (void *) p->previous);
		p = p->next;
	}
}

int main(void) 
{
	struct entryD n1, n2, n3, n4, n5, n6;
	struct entryD *list_pointer = &n1;

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

	print_dlist(list_pointer);

	return 0;
}
