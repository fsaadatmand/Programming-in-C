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
	int            value;
	struct entry   *next;
};

void insertEntry(struct entry *insertElement, struct entry *afterElement)
{
	insertElement->next = afterElement->next;   /* copy previous element's
												   pointer to the new entry */
	afterElement->next = insertElement;         /* Link the new entry to list */
}

int main(void) 
{
	void insertEntry(struct entry *insertElement, struct entry *afterElement);

	struct entry n0, n1, n2, n3, n4, n5, n6;
	struct entry *list_pointer = &n0; /* pointer to the beginning of the list */
	
	n0.next = &n1;         /* special structure to insert element at
							  the beginning of the list */

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
	
	insertEntry(&n6, &n5);

	list_pointer = list_pointer->next;       /* skip the value of the special
												structure */
	while (list_pointer != (struct entry *) 0) {
		printf("%i ", list_pointer->value);
		printf("%p\n", list_pointer->next);
		list_pointer = list_pointer->next;
	}
}
