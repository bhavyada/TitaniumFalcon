//============================================================================
// Name        : Delete_last_node.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// This program is to delete the last node from the linked list
// Input: 1->2->3->4->5->6->NULL
// Output: 1->2->3->4->5->NULL

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Node
{
	int Data;
	struct Node* Next;
};


//The key point here is to check whether current->Next != NULL
void Delete_last_node(struct Node **head)
{
	struct Node* current = *head;
	struct Node* prev = NULL;
	while(current->Next != NULL)
	{
		prev = current;
		current = current->Next;
	}
	prev->Next = NULL;
}


void push(struct Node** head, int value)
{
	struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
	Newnode->Data = value;
	Newnode->Next = *head;
	*head = Newnode;
}

void Print_Linked_list(struct Node* head)
{
	printf("\n");
	struct Node* current = head;
	while(current != NULL)
	{
		printf("%d\t",current->Data);
		current = current->Next;
	}
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
	Delete_last_node(&head);
	Print_Linked_list(head);

}
