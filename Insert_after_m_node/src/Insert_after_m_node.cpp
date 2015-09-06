//============================================================================
// Name        : Insert_after_m_node.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 ============================================================================
 Name        : Insert_after_m_node.c
 Author      : Bhavya Kattapuni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// This program is to illustrate how to add a node after a particular node. However the head and
// that particular node pointer are passed as arguments to the function.
#include <stdio.h>
#include <stdlib.h>
#include<iostream>

struct Node{
	int Data;
	struct Node* Next;
};

struct Node* push(struct Node** head, int value)
{
	struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
	Newnode->Data = value;
	Newnode->Next = *head;
	*head = Newnode;
	return Newnode;
}

void PrintLinkedList(struct Node* newList)
{

	printf(" Linked List");
	while(newList!= NULL)
	{
		printf("\t");
		printf("%d",newList->Data);
		newList = newList-> Next;
	}
	printf("\n");
}

void Insert_after(struct Node** head, struct Node* node, int num)
{
	if(head == NULL)
	{
		return;
	}
	struct Node* current = *head;
	struct Node* nextnode = current->Next;
	struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
	newnode->Data = num;
	newnode->Next = NULL;
	while(current != NULL)
	{
		if(current == node)
		{
			nextnode = current->Next;
			current->Next = newnode;
			newnode->Next = nextnode;
		}
		current = current->Next;

	}
}

int main(void) {
	struct Node* head = NULL;
	 push(&head,5);
	 //since I want only node4 in the declaration I have only assigned the value to node4.
	 struct Node* node4 = push(&head,4);
	 push(&head,3);
	 push(&head,2);
	 push(&head,1);

	PrintLinkedList(head);
	Insert_after(&head, node4, 10);
	PrintLinkedList(head);
	return 0;
}
