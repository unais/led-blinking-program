/****************************************************************
Qn:
Write a function DeleteList() that takes a list, deallocates all of its memory and sets its
head pointer to NULL (the empty list).
void DeleteListTest() {
struct node* myList = BuildOneTwoThree();
// build {1, 2, 3}
DeleteList(&myList); // deletes the three nodes and sets myList to NULL
}


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

// Build and return the list {1, 2, 3}
struct node* BuildOneTwoThree() {
	struct node* head = NULL; // Start with the empty list
	Push(&head, 3);// Use Push() to add all the data
	Push(&head, 2);
	Push(&head, 1);

	return(head);
}

main()
{
	void DeleteListTest();

	DeleteListTest();

}


void DeleteList(struct node** headRef);
void DeleteListTest(){
	struct node* myList = BuildOneTwoThree();

	DeleteList(&myList);	
}

void DeleteList(struct node** headRef){
	struct node* current;

	for(current = *headRef; current != NULL; current = current -> next)
		free(current);
	*headRef = NULL;
}
