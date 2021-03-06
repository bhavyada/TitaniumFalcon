//============================================================================
// Name        : Detect_a_loop_and_remove.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// This program is an illustration to detect a loop and find the entry node and also remove the loop


#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct Node
{
	int Data;
	struct Node* Next;
};

struct Node* MeetingNode(struct Node* head)
{
	struct Node* slow_p = head;
	struct Node* fast_p = head;
	while ((slow_p != NULL) && (fast_p != NULL) && (fast_p->Next != NULL))
		{
			slow_p = slow_p->Next;
			fast_p = fast_p->Next->Next;
			if (slow_p == fast_p)
			{
				printf("Loop detected");
				return fast_p;
			}
		}
	return NULL;
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

struct Node* EntryNode(struct Node* head)
{
	struct Node* meetingNode = MeetingNode(head);
	if (meetingNode == NULL)
		return NULL;
	struct Node* pNode = meetingNode;
	int Num_of_nodes = 0;
	while(pNode->Next != meetingNode)
	{
		pNode= pNode->Next;
		Num_of_nodes++;
	}
	Num_of_nodes++;
    printf("\nThe number of nodes in the loop is %d",Num_of_nodes);
	pNode = meetingNode;
    struct Node* pNode1;
	struct Node* pNode2 = head;
	while(pNode != pNode2)
	{
		pNode1 = pNode;
		pNode = pNode->Next;

		pNode2 = pNode2->Next;
	}
	pNode1->Next = NULL;
	Print_Linked_list(head);
	return pNode;
}

int main()
{
	struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
	node5->Data = 5;
	node5->Next = NULL;
	struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
	node4->Data = 4;
	node4->Next = node5;
	struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
	node3->Data = 3;
	node3->Next = node4;
	struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
	node2->Data = 2;
	node2->Next = node3;
	struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	node1->Data = 1;
	node1->Next = node2;

	struct Node* head = node1;
	node5->Next = node2;

	struct Node* Node = EntryNode(head);
	printf("\nEntry point of loop is at Node %d",Node->Data);
	return 0;

}
