/*
 * 6. Develop insertEntry() and removeEntry() functions for a doubly linked
 * list that are similar in function to those developed in previous exercises
 * for a singly linked list. Why can your removeEntry() function now take as
 * its argument a direct pointer to the entry to be removed from the list?
 * (alternate version)
 *
 * Answer: 
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>

struct entry {
	int          value;
	struct entry *previous;
	struct entry *next;
};

void insertEntry (struct entry *elementIn, struct entry *location, int position)
{	
	if (position == 1)                    /* Insert element AFTER location */
		if (location->next != (struct entry *) 0) {
			elementIn->next = location->next;
			(location->next)->previous = elementIn;
			location->next = elementIn;
			elementIn->previous = location;
		} else {                           /* Last element in the list */
			elementIn->next = location->next;
			location->next = elementIn;
			elementIn->previous = location;
		}
	 else if (position == -1) {           /* Insert elementIn BEFORE location */
		if (location->previous != (struct entry *) 0) {
			elementIn->previous = location->previous;
			(location->previous)->next = elementIn;
			location->previous = elementIn;
			elementIn->next = location;
		} else 
			printf("No element insert value before \n\n");
	 }
}

void removeEntry(struct entry *element)
{
	if (element->next != (struct entry *) 0) {
		(element->previous)->next = element->next;
		(element->next)->previous = element->previous;
	} else                                 /* Last element in the list */
		(element->previous)->next = element->next;
}

int main(void) 
{
	void insertEntry (struct entry *elementIn, 
			struct entry *location, int position), 
		 removeEntry(struct entry * element);

	struct entry n0, n1, n2, n3, n4, n5, n6;
	struct entry *list_pointer = &n0, *end_pointer = &n5;

//	n0.previous = (struct entry *) 0;
	n0.next = &n1;

	n1.value = 100;
	n1.previous = &n0;
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

	n6.value = 600;

	insertEntry(&n6, &n5, 1);
//	removeEntry(&n1);

	list_pointer = list_pointer->next;
	while (list_pointer != (struct entry *) 0) {
		printf("%i ", list_pointer->value);
		printf("%p\n", list_pointer->next);
		list_pointer = list_pointer->next;
	}
	
	printf("\nprevious values\n");

	while (end_pointer != (struct entry *) 0) {
		printf("%i ", end_pointer->value);
		printf("%p\n", end_pointer->previous);
		end_pointer = end_pointer->previous;
	}
	return 0;
}
