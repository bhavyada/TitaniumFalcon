//============================================================================
// Name        : Find_middle_element.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// This program is to find the middle element of the linked list. The algorithm used here is to make
//use of two pointers i.e. a slow pointer and a fast pointer. the fast pointer moves at twice the speed of
// the slow pointer. When the fast pointer reaches the end of the linked list the slow pointer reaches
// the middle.
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct Node
{
	int Data;
	struct Node* Next;
};

void push(struct Node** head, int value)
{
	struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
	Newnode->Data = value;

	Newnode->Next = *head;
	*head = Newnode;
}

void Print_Linked_list(struct Node* head)
{
	struct Node* current = head;
	printf("\n");
	while(current != NULL)
	{
		printf("%d\t",current->Data);
		current = current->Next;
	}
}

int middle_node_value(struct Node** head)
{
	struct Node* slow_p = *head;
	struct Node* fast_p = (*head)->Next;
	while((fast_p != NULL) && (fast_p->Next != NULL))
	{
		slow_p = slow_p->Next;
		fast_p = fast_p->Next->Next;
	}
	return (slow_p ->Data);
}

int main()
{
	struct Node* head = NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	Print_Linked_list(head);
	printf("\nThe value of the middle node is %d",middle_node_value(&head));

}