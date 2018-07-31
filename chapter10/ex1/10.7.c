/* Traversing a linked list */

#include <stdio.h>

int main(void) 
{
	struct entry {
		int          value;
		struct entry *next;
	};

	struct entry n1, n2, n3;
	struct entry *list_pointer = &n1;

	n1.value = 100;
	n1.next  = &n2;

	n2.value = 200;
	n2.next  = &n3;

	n3.value = 200;
	n3.next  = (struct entry *) 0;    /* mark list end with null pointer */

	while (list_pointer != (struct entry *) 0) {
		printf("%i\n", list_pointer->value);
		list_pointer = list_pointer->next;
	}

	return 0;
}
