/****************************************************************
Qn:
**************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node {
	char *data;
	struct node* next;
};

void Push(struct node** headRef, char *newData) {
	struct node* newNode =
		(struct node*) malloc(sizeof(struct node));// allocate node
	newNode->data = newData;// put in the data
	newNode->next = (*headRef);// link the old list off the new node
	(*headRef) = newNode;// move the head to point to the new node
}
/*
// Build and return the list {1, 2, 3}
struct node* BuildA() {
	struct node* head = NULL; // Start with the empty list
	Push(&head, 1);// Use Push() to add all the data
	Push(&head, 2);
	Push(&head, 3);
	Push(&head, 4);

	return(head);
}

*/

/*
struct node* BuildB() {
	struct node* head = NULL; // Start with the empty list
	Push(&head, 5);// Use Push() to add all the data
	Push(&head, 6);
	Push(&head, 7);
	Push(&head, 8);

	return(head);
}

*/

void PrintList(struct node* head){
	struct node* current = head;;
	
	while(current != NULL){
		printf("%s\t", current -> data);
		current = current -> next;	
	}
	printf("\n");

}

//void Append(struct node** aRef, struct node** bRef);
main()
{
	struct node* head = NULL;
	char *c;
	int i;
 	for(i = 0;i <= 10 ; i++){
		scanf("%s",c);
		Push(&head,c);
	}
		
	PrintList(head);
}




/*

void Append(struct node** aRef, struct node** bRef){
	struct node* current = *aRef;

	while(current -> next != NULL)
		current = current -> next;
	current -> next  = *bRef;

}

*/
