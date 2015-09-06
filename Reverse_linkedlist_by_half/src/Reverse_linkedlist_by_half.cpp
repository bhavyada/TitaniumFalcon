//============================================================================
// Name        : Reverse_linkedlist_by_half.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Reverse_linkedlist_by_half.cpp
 *
 *  Created on: Aug 21, 2015
 *      Author: Bhavya
 */

// This program gives an illustration to reverse the linked list by half
// Input linkedlist : 1->2->3->4->5->6->NULL
// Output linkedlist: 3->2->1->6->5->4->NULL

// The implementation entails 3 functions
// 1) A function called reverse_first_part() which reverses the first half of the linked list and returns
// the head of the original linked list i.e. 1->2->3 is reversed to generate 3->2->1 and the pointer to 1 is
// returned

//2) A function called reverse_second_part() which reverses the second half of the linked list and returns
// the head of the reversed linked list i.e.4->5->6 is reversed to generate 6->5->4 and the pointer to 6 is
// returned

//3) The third function called join_the_halfs() is called. This first calculates the midpoint of the
// linked list using two pointers called fast_p and slow_p. The fast_p moves at twice the speed of the slow_p
// and hence when the fast_p reaches the end of the linked list the slow_p has reached the middle. so we
// pass slow_p->Next to the reverse_second_part() function and then join the variables which are returned
// by the two functions

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Node
{
	int Data;
	struct Node* Next;
};


//This function mainly creates the linked list by inserting every new node in the beginning of the list.
void Push(struct Node** head, int value)
{
	struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
	Newnode->Data = value;
	Newnode->Next = NULL;

	Newnode->Next = *head;
	*head = Newnode;
}

//This function prints the entire linked list
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

struct Node* Reverse_first_part(struct Node **head)
{
	struct Node* temp = *head;//this temp pointer captures the head pointer
	// Now we do the reversing part
	struct Node* prev = NULL;
	struct Node* current = *head;
	struct Node* nextnode;

	while(current != NULL)
	{
		nextnode = current->Next;
		current->Next = prev;
		prev= current;
		current= nextnode;
	}
	*head = prev;
	return temp;
}

struct Node* Reverse_second_part(struct Node **head)
{

	// Now we do the reversing part
	struct Node* prev = NULL;
	struct Node* current = *head;
	struct Node* nextnode;

	while(current != NULL)
	{
		nextnode = current->Next;
		current->Next = prev;
		prev= current;
		current= nextnode;
	}
	*head = prev;
	//we return the head of the reversed linked list//
	return *head;
}

void join_the_halfs(struct Node** head)
{
	if(*head == NULL || (*head)->Next == NULL)
		{
			return;
		}
	struct Node* slow_p = *head;
	struct Node* fast_p = (*head)->Next;
	while((slow_p != NULL) && (fast_p != NULL) && (fast_p->Next != NULL))
	{
		fast_p = fast_p->Next->Next;
		slow_p = slow_p->Next;
	}

	struct Node* tempnode = slow_p->Next;
	slow_p->Next = NULL;
	struct Node* head_second_part;
	head_second_part = Reverse_second_part(&tempnode);
	struct Node* tail_first_part;
	tail_first_part = Reverse_first_part(head);
	tail_first_part->Next = head_second_part;
}
int main()
{
	struct Node* head = NULL;
	Push(&head, 6);
	Push(&head, 5);
	Push(&head, 4);
	Push(&head, 3);
	Push(&head, 2);
	Push(&head, 1);
	// this function call prints all the integers in order of the linked list
	Print_Linked_list(head);
	// this function call reverses the linked list by half
	join_the_halfs(&head);
	// This prints the linked reversed by half
	Print_Linked_list(head);


}

