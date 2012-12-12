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

// Build and return the list {1, 2, 3}
struct node* BuildUnSortedList() {
	struct node* head = NULL; // Start with the empty list
	Push(&head, 23);// Use Push() to add all the data
	Push(&head, 65);
	Push(&head, 12);
	Push(&head, 24);

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
void InsertSort(struct node** headRef);

main()
{
//	struct node* newNode = NewNode();
	struct node* myList = BuildUnSortedList();
	PrintList(myList);
	InsertSort(&myList);
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

void InsertSort(struct node** headRef){
	
	struct node* Sorted = NULL;
	struct node* current;
	struct node* next;

	for(current = *headRef; current != NULL; next = current -> next){
		SortedInsert(&Sorted, current);
		current = next;
	}
	*headRef = Sorted;
	PrintList(Sorted);
}


