//============================================================================
// Name        : Delete_particular_node.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// This program is to delete a particular node in a linked given a pointer to that linked list without
// passing the header.

//Input: 1->2->3->4->5
//Output: 1->2->3->5

#include<stdio.h>
#include<iostream>
#include<stdlib.h>

//Link list node
struct Node
{
    int Data;
    struct Node* Next;
};

//pushing the new_node at the head
struct Node* push(struct Node** head_ref, int new_data)
{
    /* allocate node */
   struct Node* new_node =
             (struct Node*) malloc(sizeof(struct Node));

   /* put in the data  */
   new_node->Data  = new_data;

   /* link the new_node->Next to the old list which head was pointing to */
   new_node->Next = (*head_ref);

   /* move the head to point to the new node */
   (*head_ref)    = new_node;
   return new_node;
}

void printList(struct Node *head)
{
   struct Node *temp = head;
   while(temp != NULL)
   {
      printf("%d  ", temp->Data);
      temp = temp->Next;
   }
}

void deleteNode(struct Node *node_ptr)// suppose node_ptr = 3
{
   struct Node* temp = node_ptr->Next;// temp = 4
   node_ptr->Data = temp->Data; //data =4
   node_ptr->Next = temp->Next;
   free(temp);
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    /* Use push() to construct below list
    1->2->3->4->5  */
    struct Node* node5 = push(&head, 5);
    struct Node* node4 = push(&head, 4);
    struct Node* node3 = push(&head, 3);
    struct Node* node2 = push(&head, 2);
    struct Node* node1 = push(&head, 1);

    printf("\n Before deleting \n");
    printList(head);

    // Here we are deleting the particular node given only the pointer to that node
   deleteNode(node4);

   printf("\n After deleting \n");
   printList(head);

}