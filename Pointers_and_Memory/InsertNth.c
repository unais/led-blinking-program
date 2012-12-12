/****************************************************************
Qn:


**************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void Push(struct node** headRef, int newData) {
	struct node* newNode =
		(struct node*) malloc(sizeof(struct node));// allocate node
	newNode->data = newData;// put in the data
	newNode->next = (*headRef);// link the old list off the new node
	(*headRef) = newNode;// move the head to point to the new node
}

// Return the number of nodes in a list
int Length(struct node* head) {
	int count = 0;
	struct node* current = head;
	while (current != NULL) {
		count++;
		current=current->next;
	}
	return(count);
}


void InsertNthTest();
void InsertNth(struct node** headRef, int index, int Data);

main()
{
	InsertNthTest();
	
}

void InsertNthTest(){
	struct node* head = NULL;

	InsertNth(&head, 0, 13);
	InsertNth(&head, 1, 42);
	InsertNth(&head, 1, 5);
	InsertNth(&head, 1, 5);
	InsertNth(&head, 1, 5);
	InsertNth(&head, 1, 5);
	printf("Length = %d\n",Length(head));
//	DeleteList(&head);

}

void InsertNth(struct node** headRef, int index, int Data){
	int count;
	struct node* current;
	if (index == 0) 
		Push(headRef, Data);
	else{
		for(count = 0, current = *headRef;count < index - 1; count++, current = current -> next);	
		Push(&(current -> next), Data);

	}
	
}
