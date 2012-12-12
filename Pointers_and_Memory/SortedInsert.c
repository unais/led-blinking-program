/****************************************************************
Qn:
Write a SortedInsert() function which given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list. While Push()
allocates a new node to add to the list, SortedInsert() takes an existing node, and just
rearranges pointers to insert it into the list. There are many possible solutions to this
problem.
void SortedInsert(struct node** headRef, struct node* newNode) {
// Your code...


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
struct node* BuildSortedList() {
	struct node* head = NULL; // Start with the empty list
	Push(&head, 6);// Use Push() to add all the data
	Push(&head, 4);
	Push(&head, 3);

	return(head);
}

struct node* NewNode(){
	struct node* head = NULL;
	Push(&head, 7);
	return(head);
}

void PrintList(struct node* head){
	struct node* current = head;;
	
	while(current != NULL){
		printf("%d\t", current -> data);
		current = current -> next;	
	}
	printf("\n");

}

void SortedInsert(struct node** headRef, struct node* newNode);

main()
{
	struct node* newNode = NewNode();
	struct node* myList = BuildSortedList();
	PrintList(myList);
	SortedInsert(&myList, newNode);
	PrintList(myList);
	
	
}



void SortedInsert(struct node** headRef, struct node* NewNode){
	struct node* current;
	struct node* previous = *headRef;

	if((NewNode -> data) <= ((*headRef) -> data))
		Push(headRef, NewNode -> data);
	else{
		for(current = *headRef;current != NULL; current = current -> next){
			if((NewNode -> data) <= (current -> data)){
				Push(&(previous -> next), NewNode -> data);
				break;
			}
			previous = current;	
		} 
		
		if (current == NULL)
			Push(&(previous -> next), NewNode -> data);
			
	}
}
