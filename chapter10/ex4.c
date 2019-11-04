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
	int value;
	struct entry *next;
};

/* functions */
void removeEntry(struct entry *);
void print_list(struct entry *);

void removeEntry(struct entry *element)
{
	if (!element->next) /* if NULL */
		element->next = NULL;
	else
		element->next = element->next->next;
}

void print_list(struct entry *p)
{
	int i;

	for (i = 1; p; ++i) {
		printf("n%i (%p)\n", i, (void *) p);
		printf(" value: %i\n", p->value);
		printf(" next: %p\n", (void *) p->next);
		p = p->next;
	}
}

int main(void) 
{
	void removeEntry(struct entry *element);

	struct entry n1, n2, n3, n4, n5; /* list entries */
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
	n5.next =  NULL;

	/* remove entry after n4, i.e. n5 */
	removeEntry(&n4);

	/* special struct to insert an element at the beginning */
	struct entry n0 = {0, &n1};
	/* remove entry after n0, i.e. n1 */
	removeEntry(&n0);
	/* update list_pointer to point the new first element, i.e. n2 */
	list_pointer = n0.next; 

	print_list(list_pointer);

	return 0;
}
