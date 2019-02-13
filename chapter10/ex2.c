/* 
 * 2. Write a function called insertEntry() to insert a new entry into a linked
 * list. Have the procedure take as arguments a pointer to the list entry to be
 * inserted (of type struct entry as defined in this chapter), and a pointer to
 * an element in the list after which the new entry is to be inserted.
 *
 * by Faisal Saadatmand
 */

#include <stdio.h>

struct entry {
	int            value;
	struct entry   *next;
};

void insertEntry(struct entry *insertElement, struct entry *afterElement)
{
	insertElement->next = afterElement->next;   /* Copy previous element's
												   pointer to the new entry */
	afterElement->next = insertElement;         /* Link the new entry to list */
}

int main(void) 
{
	void insertEntry(struct entry *insertElement, struct entry *afterElement);

	struct entry n1, n2, n3, n4, n5, n6;
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
	n5.next = (struct entry *) 0; /* Mark list end with null pointer */

	n6.value = 600;
	
	insertEntry(&n6, &n1);

	while (list_pointer != (struct entry *) 0) {
		printf("%i ", list_pointer->value);
		printf("%p\n", list_pointer->next);
		list_pointer = list_pointer->next;
	}

	return 0;
}
