//============================================================================
// Name        : Merge_two_sorted_list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// This program is to merge two sorted linked list. So we create a dummy node and we keep inserting
// to the end of the dummy node

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

struct Node* Merge_linked_list(struct Node* head1, struct Node* head2)
{
	struct Node dummy;
	struct Node* dummy_tail = &dummy;
	dummy.Next = NULL;

	if (head1 == NULL)
	{
		dummy_tail-> Next = head2;
	}
	else if(head2 == NULL)
	{
		dummy_tail->Next = head1;
	}
	while((head1 != NULL) && (head2 != NULL))
	{
		if (head1->Data < head2->Data)
		{
			dummy_tail->Next = head1;
			head1 = head1->Next;
		}
		else
		{
			dummy_tail->Next = head2;
			head2 = head2->Next;
		}
		dummy_tail = dummy_tail->Next;
	}
	return dummy.Next;
}

int main()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* merged = NULL;
	push(&head1,26);
	push(&head1,18);
	push(&head1,9);
	push(&head1,8);
	push(&head1,2);
	Print_Linked_list(head1);

	push(&head2,32);
	push(&head2,22);
	push(&head2,19);
	push(&head2,16);
	push(&head2,9);
	Print_Linked_list(head2);

	merged = Merge_linked_list(head1,head2);
    Print_Linked_list(merged);

}
