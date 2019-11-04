/* 
 * 3. The function developed in exercise 2 only inserts an element after an
 * existing element in the list, thereby preventing you from inserting a new
 * entry at the front of the list. How can you use this same function and yet
 * overcome this problem? (Hint: Think about setting up a special structure to
 * point to the beginning of the list.)
 *
 * by Faisal Saadatamnd
 */

#include <stdio.h>

struct entry {
	int value;
	struct entry *next;
};

void insertEntry(struct entry *, struct entry *);

void insertEntry(struct entry *newElement, struct entry *ListElement)
{
	/* Copy previous element's pointer to the new entry */
	newElement->next = ListElement->next;
	/* Link the new entry to list */
	ListElement->next = newElement;
}

int main(void) 
{
	struct entry n1, n2, n3, n4, n5, n6; /* list entries */
	struct entry *list_pointer = &n1; /* pointer to the beginning of the list */

	n1.value = 100;
	n1.next = &n2;

	n2.value = 200;
	n2.next = &n3;
	
	n3.value = 300;
	n3.next = &n4;

	n4.value = 400;	
	n4.next = &n5;
	
	n5.value = 500;
	n5.next = NULL;

	/* new entrey */
	n6.value = 600;
	n6.next = NULL;

	/* special struct to insert an element at the beginning */
	struct entry n0 = {0, &n1};
	/* insert n6 after n0, i.e before n1 */
	insertEntry(&n6, &n0);
	/* update list_pointer to point the new first element, i.e. n6 */
	list_pointer = n0.next;

	int i = 1;
	while (list_pointer != NULL) {
		printf("n%i (%p)\n", i++, list_pointer);
		printf(" value: %i\n", list_pointer->value);
		printf(" next: %p\n", list_pointer->next);
		list_pointer = list_pointer->next;
	}
}
