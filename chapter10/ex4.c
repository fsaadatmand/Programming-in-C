/* 
 * 4. Write a function called removeEntry() to remove an entry from a linked
 * list. The sole argument to the procedure should be a pointer to the list.
 * Have the function remove the entry after the one pointed to by the argument.
 * (Why can’t you remove the entry pointed to by the argument?) You need to use
 * the special structure you set up in exercise 3 to handle the special case of
 * removing the first element from the list.
 *
 * by Faisal Saadatamnd
 */

#include <stdio.h>

struct entry {
	int            value;
	struct entry   *next;
};

void removeEntry(struct entry *element)
{
	if (element->next != (struct entry *) 0)
		element->next = element->next->next;
	else
		printf("End of list... Nothing to remove\n");
}

int main(void) 
{
	void removeEntry(struct entry *element);

	struct entry n0, n1, n2, n3, n4, n5;
	struct entry *list_pointer = &n0; /* pointer to the beginning of the list */
	
	n0.value = 0;
	n0.next = &n1;         /* Special structure to remove an element at the 
							  beginning of the list */

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

	removeEntry(&n0);

	list_pointer = list_pointer->next;       /* Hide the special structure */
	while (list_pointer != (struct entry *) 0) {
		printf("%i ", list_pointer->value);
		printf("%p\n", list_pointer->next);
		list_pointer = list_pointer->next;
	}
	return 0;
}
