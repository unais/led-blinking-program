/****************************************************************
Qn:
Write a Count() function that counts the number of times a given int occurs in a list. The
code for this has the classic list traversal structure as demonstrated in Length().
void CountTest() {
List myList = BuildOneTwoThree();
int count = Count(myList, 2);
// build {1, 2, 3}
// returns 1 since there's 1 '2' in the list
}
*
Given a list and an int, return the number of times that int occurs
in the list.

int Count(struct node* head, int searchFor) {
// Your code


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
	Push(&head, 2);

	return(head);
}

main()
{
	int CountTest();
	printf("Result : %d\n",CountTest());
}



int CountTest(){
	struct node* myList = BuildOneTwoThree();

	int count = Count(myList, 2);
	return(count);
}

int Count(struct node* head, int searchFor){
	int counts;
	struct node* current = head;
	for(counts = 0; current != NULL; current = current -> next)
		if(current -> data == searchFor)
			counts++;
	return(counts);
}
