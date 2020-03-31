

#include "LIST.h"


int main()
{
	Node head;//Í·½áµã
	InitList(&head);
	Node* p = NULL;

	//InsertHead(&head, 1);
	//InsertHead(&head, 2);
	//InsertHead(&head, 3);
	//InsertHead(&head, 4);

	InsertTail(&head, 5);
	InsertTail(&head, 4);
	InsertTail(&head, 3);
	InsertTail(&head, 2);
	InsertTail(&head, 1);

	//ShowList(&head);

	p = LastKNode(&head,1);
	printf("%d\n", p->data);
	return 0;
}



