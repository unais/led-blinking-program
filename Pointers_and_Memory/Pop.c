/****************************************************************
Qn:
Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty list, deletes
the head node, and returns the head node's data. If all you ever used were Push() and
Pop(), then our linked list would really look like a stack. However, we provide more
general functions like GetNth() which what make our linked list more than just a stack.
Pop() should assert() fail if there is not a node to pop. Here's some sample code which
calls Pop()....

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
//	Push(&head, 4);
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
	void PopTest();
	PopTest();
}


int Pop(struct node** headRef);
void PopTest(){
	struct node* head = BuildOneTwoThree();
	int a = Pop(&head);
	printf("Pop1 : %d\n",a);
	int b = Pop(&head);
	printf("Pop2 : %d\n",b);
	int c = Pop(&head);
	printf("Pop3 : %d\n",c);
	int len = Length(head);
	printf("Length : %d\n",len);
}

int Pop(struct node** headRef){
	int Data ;
	struct node* current = *headRef;
	Data = current -> data;
	*headRef = current -> next;
	free(current);	
	return(Data);
}	
