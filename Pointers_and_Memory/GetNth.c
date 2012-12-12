/****************************************************************
Qn:
Write a GetNth() function that takes a linked list and an integer index and returns the data
value stored in the node at that index position. GetNth() uses the C numbering convention
that the first node is index 0, the second is index 1, ... and so on. So for the list {42, 13,
666} GetNth() with index 1 should return 13. The index should be in the range [0..length-
1]. If it is not, GetNth() should assert() fail (or you could implement some other error
case strategy).
void GetNthTest() {
struct node* myList = BuildOneTwoThree();
int lastNode = GetNth(myList, 2);
}
// build {1, 2, 3}
// returns the value 3
Essentially, GetNth() is similar to an array[i] operation — the client can ask for
elements by index number. However, GetNth() no a list is much slower than [ ] on an
array. The advantage of the linked list is its much more flexible memory management —
we can Push() at any time to add more elements and the memory is allocated as needed.
// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
int GetNth(struct node* head, int index) {
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
	Push(&head, 1);

	return(head);
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


main()
{
	int GetNthTest();
	int NthNum = GetNthTest();
	if(NthNum < 0)
		printf("Result : In valid entry\n");
	else
		printf("Result : %d\n",NthNum);
}

int GetNthTest(){
	struct node* myList = BuildOneTwoThree();
	int lastNode = GetNth(myList, 2);
	return(lastNode);
}

int GetNth(struct node* head, int index){
	int i;
	struct node* current;
	
	if(index >= Length(head))
		return -1;
	else
		for(current = head,i = 0;current != NULL ;current = current -> next,i++)
			if(i == index)
				return(current -> data);

}

