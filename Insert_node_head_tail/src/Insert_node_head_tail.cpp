/*
 * insert_at_head_tail.cpp
 *
 *  Created on: Aug 21, 2015
 *      Author: Bhavya
 */

// This program gives an illustration to enter a node to linkedlist at the beginning and
// the end.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


//This creates the structure of a node which contains a data and a next pointer
struct Node
{
	int Data;
	struct Node* Next;
};

//This function inserts a node at the beginning. The next pointer of the newnode connects to the present head
// then the head is moved to point to the newnode which means as every node is inserted it gets inserted
// to the head.
void insert_to_beginning(int value, struct Node** headref)
{
	struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
	Newnode->Data = value;


	Newnode->Next = *headref;
	*headref = Newnode;
}

//This function inserts at the end of the list. The current pointer traverses till the end of the list and
// the prev pointer holds the last node. then the newnode is inserted to the next pointer of the prev pointer
// which means adding the node to the end of the list.
void insert_at_end(int value, struct Node** headref)
{
	struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
	Newnode->Data = value;
	Newnode->Next = NULL;

	struct Node *current = *headref;
	struct Node* prev = NULL;
	while(current != NULL)
	{
		prev = current;
		current = current->Next;

	}
	prev->Next = Newnode;

}


// This function prints the entire list given the pointer to the head//
void Print_Linked_list(struct Node *head)
{
	struct Node* current = head;
	while(current != NULL)
	{
		printf("%d\t", current->Data);
		current = current->Next;
	}
}

int main()
{

	//driver program to run the test.
	struct Node* head = NULL;
	insert_to_beginning(2,&head);
	insert_to_beginning(3,&head);
	insert_to_beginning(4,&head);
	insert_to_beginning(5,&head);
	insert_to_beginning(6,&head);

	insert_at_end(18,&head);
	insert_at_end(19,&head);
	insert_at_end(20,&head);
	insert_at_end(21,&head);
	insert_at_end(22,&head);

	Print_Linked_list(head);
	return 0;
}


